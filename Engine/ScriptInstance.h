#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class ScriptInstance
{
public:
    lua_State* luaState = nullptr;

    void Update(float deltaTime);
    void Despawn();

    ScriptInstance(lua_State* state)
    {
        luaState = state;
    }
};