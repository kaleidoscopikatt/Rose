#include "ScriptHandler.h"

#include <filesystem>

#include "Engine.h"

Screen* GetScreen(lua_State* state)
{
    return *static_cast<Screen**>(lua_getextraspace(state));
}

/* Builtin Lua Functions */

int Builtin_Print(lua_State* state)
{
    const char* msg = luaL_checkstring(state, 1);
    std::cout << "[LUA] - " << msg << std::endl;
    return 0;
}

int Builtin_SetBackgroundColour(lua_State* state)
{
    Screen* screen = GetScreen(state);

    int r = luaL_checkinteger(state, 1);
    int g = luaL_checkinteger(state, 2);
    int b = luaL_checkinteger(state, 3);
    int a = luaL_checkinteger(state, 4);

    screen->SetBackgroundColour(new Colour((int)r, (int)g, (int)b, (int)a));
    return 0;
}

/* ScriptHandler Logic */

bool ScriptHandler::DeclareLuaState()
{
    luaState = luaL_newstate();
    if (luaState != nullptr)
    {
        luaL_openlibs(luaState);
        return true;
    }

    return false;
}

void ScriptHandler::RegisterEngineGlobals(lua_State* state)
{
    lua_register(state, "print", Builtin_Print);
    lua_register(state, "SetBackgroundColour", Builtin_SetBackgroundColour);
}

int ScriptHandler::PrepareScript(const std::string& path, lua_State* state)
{
    if (!state)
        return -1;

    int loadResult = luaL_dofile(state, path.c_str());
    if (loadResult == LUA_OK)
    {
        *static_cast<Screen**>(lua_getextraspace(luaState)) = this->screen;
        this->RegisterEngineGlobals(state);

        scripts.push_back(new ScriptInstance(state));
        
        lua_getglobal(state, "Init");
        if (!lua_isfunction(state, -1))
        {
            lua_pop(state, 1);
            std::cerr << "[Script Error] - Missing required function: Init()";
            return -1;
        }
        
        if (lua_pcall(state, 0, 0, 0) != LUA_OK)
        {
            std::cerr << "[Lua Runtime Error] " 
                      << lua_tostring(state, -1) 
                      << std::endl;

            lua_pop(state, 1);
            return -1;
        }
    }
    
    return -1;
}

bool ScriptHandler::Init(Screen* newScreen)
{
    this->screen = newScreen;
    
    std::cout << "ScriptHandler.Init() begin" << std::endl;
    if (this->DeclareLuaState())
    {
        std::string path = std::filesystem::current_path().string() + "/Game/hoved.lua";
        if (std::filesystem::exists(path))
        {
            this->PrepareScript(path, luaState);
            return true;
        }

        std::cout << "ScriptHandler.Init() - Cannot load hoved.lua!" << std::endl;
        return false;
    }

    std::cout << "ScriptHandler.Init() - Cannot initialise Lua!" << std::endl;
    return false;
}

void ScriptHandler::Liquidate()
{
    if (luaState != nullptr)
    {
        lua_close(luaState);
        luaState = nullptr;
    }
}

void ScriptHandler::Update(float deltaTime)
{
    for (ScriptInstance* script : scripts)
    {
        script->Update(deltaTime);
    }
}
