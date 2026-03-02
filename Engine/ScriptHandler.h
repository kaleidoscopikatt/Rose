#pragma once

#include <iostream>
#include <vector>

#include "Screen.h"
#include "ScriptInstance.h"

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

class ScriptHandler
{
public:
    bool DeclareLuaState();
    bool Init(Screen* newScreen);

    void Update(float deltaTime);

    void Liquidate();

    int PrepareScript(const std::string& path, lua_State* state);
    void RegisterEngineGlobals(lua_State* state);

private:
    Screen* screen = nullptr;
    lua_State* luaState = nullptr;

    std::vector<ScriptInstance*> scripts;
};
