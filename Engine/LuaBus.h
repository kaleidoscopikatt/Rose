#pragma once
#include <lua.h>

class LuaBus
{
public:
    bool DeclareLuaState();
    bool Init();

    void Liquidate();

private:
    lua_State* luaState = nullptr;
};
