orange-porridge
===============

A space shoot-em-up game with gravity and stuff. This project is currently unnamed, but aliased under the code-name "Orange Porridge"


Code Stuff
================
Here I will try to explain what happens in some of the classes. The basic flow is that the main.cpp spins up the engine which initializes all of the allegro libraries, then jumps into the allegro event loop. game.h is then called in to handle game-realted functions.

engine.h
----------------
Handles all of the allegro and behind the scenes stuff.
- Allegro event loop
- Key presses
- Mouse movements

game.h
----------------
When the engine is spun up it starts rendering data from game.h

Should incluse both Draw() and Update() functions.

entity.h
---------------
Base class for all entities in the game. Contains information such as position, velocity, an ID, rotation, etc.
