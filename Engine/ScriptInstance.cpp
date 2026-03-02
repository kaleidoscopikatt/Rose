#include "ScriptInstance.h"

#include <iostream>

void ScriptInstance::Update(float deltaTime)
{
    lua_getglobal(this->luaState, "Update");
    lua_pushnumber(this->luaState, deltaTime);

    if (lua_pcall(this->luaState, 1, 0, 0) != LUA_OK)
    {
        std::cerr << "[ROSE] - Couldn't run Update function on ScriptInstance!" << std::endl;
    }
}

void ScriptInstance::Despawn()
{
    
}
