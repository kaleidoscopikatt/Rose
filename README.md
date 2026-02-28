# Rose
***
**v1.b.1**
***
> It's important to note that, due to the nature of how C++ works, your lua code will not be compiled alongside the engine. This makes the engine portable, but is not ideal for many developers. Compilation of constant strings containing lua-file data will be available shortly.

Rose is a non-visual game engine written in C++ with the use of SDL3 for rendering, with Lua as it's target programming language. This means that all the engine code ends up being written in C++, with as-much-code-as-possible being written in Lua on the actual developer's end.

## Dependancies
***
* [Lua](https://www.lua.org/download.html) - Simple, dynamically-typed language with direct integration with C++
* [SDL3](https://github.com/libsdl-org/SDL/blob/main/INSTALL.md) - Cross-platform development library for low-level access to hardware and rendering.
* C++ and Compiler - Speaks for itself

## Documentation
***
All lua files are placed under `Rose\Game`, with all engine files being in `Rose\Engine`.

## Engine Files
| File              | Role                                                                                             |
|:------------------|:-------------------------------------------------------------------------------------------------|
| Engine.cpp        | Controls the engine-loop and maintains the time/structure of all files.                          |
| Screen.cpp        | Controls all rendering onto the screen, has helper functions in place of default SDL3 functions. |
| Colour.h          | Struct for helping with colours when rendering.                                                  |
| ScriptHandler.cpp | Main file for communicating between engine-level C++ code and game-level lua code.               |

## Lua Files
### Event Functions
Lua files in Rose have a very specific pattern, as underlined in the template lua file. Much like many programming languages, Rose requires there to be a "main" file - or an entrypoint. This file is always called `hoved.lua`. Hoved has unique functionality compared to other scripts, so it's important to keep note of these when programming.

> Unlike other scripts, Hoved does *not* have the `Despawn()` function, as the script is static and can neither be spawned or despawned.

> Unlike other scripts, if Hoved's `Init()` or `Update(deltaTime)` functions ever return `false`, the window will close. This allows you to have simple error handling outside of engine logic.

In all scripts, there are 3 in-built functions that are called automatically: `Init()` - when the window opens, or the script is spawned†, `Update(deltaTime)` - when each frame occurs, and `Despawn()` - when the instance is removed from the world.

*† Technically, you could write some code in the body of your script instead of in `Init()`, but this is not recommended as it breaks the order of code!*

### Inbuilt Functions
Scripts (lua files) in Rose come with a set of inbuilt functions *(opposed to `Init()`, `Despawn()`, etc. which are considered Event Functions)* which allow you to communicate with the engine, such as `Spawn()`, which spawns instances of scripts into the world, or `SetActive(obj)`.

A full list of them can be seen here:
**TODO**