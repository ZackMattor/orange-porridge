orange-porridge
===============

A space shoot-em-up game with gravity and stuff. This project is currently unnamed, but aliased under the code-name "Orange Porridge"


Code Stuff
================
build
---------------
 - Qt creator with Qt5.x
 - SFML 2.1
 - 

On linux it seems like you should compile it yourself. They do have a pre-built binary but i could not get that working with the newer deps in ubuntu 13.04 but it worked fine just to compile it.

engine.h
----------------
The engine handles all of the game timing, the gmae runs at 50 ticks a second. 

game.h
----------------
When the engine is spun up it starts rendering data from game.h

Should incluse both Draw() and Update() functions.

entity.h
---------------
Base class for all entities in the game. Contains information such as position, velocity, an ID, rotation, etc.
