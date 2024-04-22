
# Programming Assignment #5

**Due:2024/5/14 23:59:59**

NCCU OOP 112 spring

author: @organic_san at 2024/4/5

---

## Topic: Create a Console RPG Game (Part 1)
## Objective: Familiar with OOP concepts and connections between multiple files

## Description

### Game Objective
Create a small RPG game using the console, including processes such as entering the game, moving, switching rooms, battling, and ending.

Upon entering the game, the player will enter a room constructed of grid units of 35 * 20, which represents the map in the game. The player can use WASD keys for up, down, left, and right movements respectively. The player icon, labeled as "PL," will move within the room accordingly and will be obstructed by walls.

Rooms can be switched by moving to the left or right side of the current room. For this assignment, only horizontal room switching is considered, and vertical room switching is not. Rooms are connected horizontally via an id parameter. The room with the id of 0 is the leftmost room, and as you move right, the id increases by 1. Conversely, as you move left, the id decreases by 1. However, it's not possible to move to a room that does not exist.

Enemies with self-moving capabilities will appear in the game, requiring the design of monster movement patterns. Upon encountering a monster, the game will enter battle process. At this point, the player can choose from four options in a menu: Attack, Defend, Force Attack, and Heal. Detailed differences will be explained in subsequent assignments.

If the player is defeated by a monster, the game enters a game over state. Monsters can be set as final boss, and defeating an enemy marked as the final boss will lead to a game clear state.

A full version of the game can be played by executing this program:<br>
`./example/rpg-game-full-example`

### Assignment Objectives

The objective of this assignment is to complete the position system in the game, read data from ./src/gameobjects/room/roomdata.h into the game, and implement movement handling within the game. The goal is to allow the player icon labeled "PL" to move using WASD keys, with W, A, S, D corresponding to up, left, down, and right movements respectively. Additionally, handle obstacles such as walls, rocks, and water blocking the player's path, while doors and grasses do not obstruct the player's movement.

In this assignment, the main goals are the use objects, and object inheritance.

Render function is already included in the assignment files, so there's no need to handle output formatting.

### Content to be Completed
- Complete the position class.
- Rewrite the Player class to inherit from the GameObject class.
- Complete the Player class and the Room class.
- Design the run() function of the Controller class and handle the logic inside.


## Grading Criteria
| Grading Criteria | score |
| - | - |
| File Upload | 30 pt |
| Compilation Successful | 20 pt |
| Player (PL) can move | 20 pt |
| Player (PL) movement is hindered by walls | 10 pt |
| Player class inherits from GameObject class and corresponding modifications are made | 20 pt |
| **total** | **100 pt** |


## Assignment Directory
`/usr/local/class/oop/assign/assign5`
or https://github.com/oopnccucs/assign5


## Submission Instructions
In the OOP host, navigate to the assign5 directory and enter the following command:
```
/usr/local/class/oop/bin/submit 5
```
to submit this assignment.


## Sample Output
Please refer to the execution result in `./example/rpg-game-part1-example`. If successful, the following image will appear:![pic](https://i.imgur.com/lhKgeVc.png)

Where `WW` represents grass, `██` represents walls, `DR` represents doors, and `PL` represents the player character.

Names and types of room objects are recorded in `./src/gameobjects/room/roomstate.h`.

Players can move the `PL` using WASD, and movement will be obstructed by walls.


## Files in the Assignment Directory

- `./src/main.cpp`: <br>
  Handles switching to console mode upon entering the game, captures keyboard input, and calls `game.lifeCycle(action)` periodically to create the game loop. The processed input becomes the entry point of each frame in the game.<br>
  No need to modify the content of this file.

- `./src/gamecore`: <br>
  Handles external operations received by the game.<br>
  No need to modify the content of this folder.

- `./src/functions`:<br>
  Includes `AnsiPrint` and `position`. AnsiPrint does not need modifications, while `position` is needs to be completed.

- `./src/controller`:<br>
  Handles in-game responses. The `run()` function, called by `gamecore`, is the main loop of the game, executed once per frame.<br>
  In this assignment, player operations and movement decisions need to be completed here.

  - `enviroment`:<br>
    Stores environmental variables of the game. `SPEED` represents frames per second (s).

- `./src/gameobjects`:<br>
  Primarily handles game objects, including `player`, `room`, and `gameobject`.

  - `player`:<br>
    Inherits from the `GameObject` class and needs to complete functions related to operations.

  - `room`:<br>
    Contains room contents and related behavior handling. The `Room` class represents a single room. Please complete data input and logic processing here.

  - `gameobject`:<br>
    Contains basic definitions of game objects. Please complete this class.

- `./src/gameprocess`:<br>
  Currently records information about game process states, which will be gradually expanded in subsequent assignments.


## Implementation Notes

Compile: `$make`

Run: `$make run`

The provided files for the assignment may not include all member functions that might be used. If additional functions would aid in the completion of the assignment, feel free to add them into classes. Existing functions in the assignment can also be modified.

For example, when dealing with coordinates, considering that the input format is direction rather than coordinate position, adding a `Direction` struct might facilitate the conversion between input and operation.