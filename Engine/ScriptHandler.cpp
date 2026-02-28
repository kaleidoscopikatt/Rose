#include "ScriptHandler.h"

#include <iostream>
#include <filesystem>

/* Builtin Lua Functions */

int Builtin_Print(lua_State* state)
{
    const char* msg = luaL_checkstring(state, 1);
    std::cout << "[LUA] - " << msg << std::endl;
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

void RegisterEngineGlobals(lua_State* state)
{
    lua_register(state, "print", Builtin_Print);
}

int PrepareScript(const std::string& path, lua_State* state)
{
    if (!state)
        return -1;

    int loadResult = luaL_dofile(state, path.c_str());
    if (loadResult == LUA_OK)
    {
        RegisterEngineGlobals(state);
        
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

bool ScriptHandler::Init()
{
    std::cout << "ScriptHandler.Init() begin" << std::endl;
    if (this->DeclareLuaState())
    {
        std::string path = std::filesystem::current_path().string() + "/Game/hoved.lua";
        if (std::filesystem::exists(path))
        {
            PrepareScript(path, luaState);
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
    
}
