# TextGraphGameEngine

## Summary
The TextGraphGameEngine is a game engine that specializes in supporting text-based or ASCII character graphical games. In future iterations, it will allow for quick implementation of text graphics, the manipulation or "physics" of the text characters, the logic of the games, the sound, and even the artificial intelligence. Games that can be created with the aid of the engine include 
Rogue-like games, simple platformers, and abstract simulations. 

## Building
To build the project currently, install g++ 8.3.x and run the following command at the root of this project:
`g++ main.cpp Graphics/*.cpp`

This should produce a file called `a.out`

## Running
Run the `a.out` file (or whatever the file was named using -o flag) with the following command:
`./a.out`

At the moment, this just runs the Catch tests for the program. In the future, there will be separate test and program executables that can be compiled. 
