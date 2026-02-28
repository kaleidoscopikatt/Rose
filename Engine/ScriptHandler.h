#pragma once

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <luaconf.h>
#include <lauxlib.h>
}

class ScriptHandler
{
public:
    bool DeclareLuaState();
    bool Init();

    void Update(float deltaTime);

    void Liquidate();

    void RegisterEngineGlobals(lua_State* state);

private:
    lua_State* luaState = nullptr;
};
