#include "LuaBus.h"

#include <iostream>
#include <lualib.h>
#include <lauxlib.h>

#include "SDL3/SDL_log.h"

lua_State* luaState;

bool LuaBus::DeclareLuaState()
{
    luaState = luaL_newstate();
    if (luaState != nullptr)
    {
        luaL_openlibs(luaState);
        return true;
    }

    return false;
}

bool LuaBus::Init()
{
    if (this->DeclareLuaState())
        return true;

    std::cout << "LuaBus.Init() - Cannot initialise Lua!\n";
    return false;
}

void LuaBus::Liquidate()
{
    lua_close(luaState);
}