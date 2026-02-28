--[[
    hoved.lua is the entrypoint from C++ -> Lua
    
    Hoved CANNOT be instantiated, and so Despawn() will never run
    for hoved until the window closes!
    
    Hoved is fully able to spawn any ScriptInstance it desires, and
    like every other script, Update() always runs every frame, and Init()
    upon it's first frame of existence (hoved's Init() happens when the window
    opens).
    
    Unlike other scripts, if Hoved's Update() or Init() functions return false at
    any point, the window will close.
]]

-- Technically, you could just write code without this function, but it is recommended
-- to always use Init(), instead.
function Init()
    print("Hello, World! Coming from Lua, straight to C++!")
end

function Update(deltaTime) end -- Runs every frame
function Despawn() end -- Runs just before the ScriptInstance gets removed