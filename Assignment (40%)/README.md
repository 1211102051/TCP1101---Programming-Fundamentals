# Alien vs. Zombie

Hi. This is the **Alien vs Zombie** game created by our group.  

In this game, you will be an Alien and your goal is to kill all the zombies in the gameboard.
Once your goal is achieved, you will win the game and maybe there's a hidden prize awaiting you.
Refer to video demo below to see how's the game looks like 👇

[Video Demo by **Person 3**](https://www.youtube.com/watch?v=dQw4w9WgXcQ).

[Read more...](Assignment.pdf)
###### P.S we actually started doing this on Friday due to final exam.
## Compilation Instructions
Windows
> g++ src\main.cpp lib\board.cpp lib\character.cpp lib\display.cpp lib\menus.cpp

Unix-like OS (Make sure /usr/bin and /usr/local/bin are in your path)
> make

## User Manual
The game is actually very easy to navigate!
### Main Menu
1. New Game (Create new game)
2. Load Game (Load game from savefiles)
3. Quit

### Game Phase
During the game phase, Alien will be given multiple commands:
- Move
- Arrow
- Help
- Save/Load
- Quit

The commands are pretty obvious. Type help to list out all the command ingame.  

Moving the alien anywhere will lead the zombies to attack you.
Changing the arrow during Alien turn however does not prompt the zombie to move. 

## Dev Manual
### Directories
1. lib (libraries)
2. save (savefiles)
3. src (main files here)

##### If you encounter any segfault, that's not our problem.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Names removed for anonymity. 

- Person 1
- Person 2
- Person 3


