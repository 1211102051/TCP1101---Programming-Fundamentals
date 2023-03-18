// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT0L
// Names: Person 1 | Person 2 | Person 3
// IDs: 1111111111 | 1111111111 | 1111111111
// Emails: 1111111111@student.mmu.edu.my | 1111111111@student.mmu.edu.my | 1111111111@student.mmu.edu.my
// Phones: 0166666666 | 0166666666 | 0166666666
// *********************************************************

// header
#include "../lib/data.hpp"
#include "../lib/board.hpp"
#include "../lib/menus.hpp"
#include "../lib/display.hpp"
#include "../lib/character.cpp"
#include "../lib/character.hpp"
#include <algorithm>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// global variable
int row = 5;
int column = 9;
int zombiecount = 1;
bool newGame = false;
bool exitGame = false;
bool exitMenu = false;
bool savedGame = false;
bool gameToggle = false;

Board board(column, row);
vector<Zombie> zombies;
Zombie zombie;
Alien alien(&board, (column + 2) / 2, (row + 2) / 2, 100, 0);

int clearScreen()
{
#ifdef _WIN32
    return system("cls");
#elif __linux__ || __APPLE__ || __FreeBSD__
    return system("clear");
#endif
}

int pause()
{
#ifdef _WIN32
    return system("pause");
#elif __linux__ || __APPLE__ || __FreeBSD__
    return system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

void createPlayer()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Welcome back"
         << " " << name << " ! " << endl;
    menu::settingMenu(row, column, zombiecount);
    menu::changeSettings(row, column, zombiecount);
    clearScreen();
    board.setDimY(row);
    board.setDimX(column);
    board.init(column, row);
    for (int i = 0; i < zombiecount; i++)
    {
        zombie.setAttribute(row, column, i + 1, &board);
        // inserting objects to vector
        zombies.push_back(zombie);
    }
    alien.setRow((row + 2) / 2);
    alien.setColumn((column + 2) / 2);
    newGame = false;
}

void loadPlayer()
{
    loadGame();
    savedGame = false;
}

void startGame()
{
    string playerInput;
    bool alienTurn;
    do
    {
        board.resetTrail(); //reset trail left by alien
        alien.resetAttack(); //alien's attack resetted after every move
        alien.display();
        hud();
        cout << "Command => ";
        cin >> playerInput;
        transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::tolower);

        if (playerInput == "up")
        {
            alien.moveUp();
            alienTurn = false;
        }
        else if (playerInput == "down")
        {
            alien.moveDown();
            alienTurn = false;
        }
        else if (playerInput == "left")
        {
            alien.moveLeft();
            alienTurn = false;
        }
        else if (playerInput == "right")
        {
            alien.moveRight();
            alienTurn = false;
        }
        else if (playerInput == "arrow")
        {
            switchArrow();
            return;
        }
        else if (playerInput == "help")
        {
            menu::help();
        }
        else if (playerInput == "save")
        {
            saveGame();
        }
        else if (playerInput == "load")
        {
            savedGame = true;
            return;
        }
        else if (playerInput == "back")
        {
            zombies.clear();
            exitMenu = false;
            gameToggle = false;
            return;
        }
        else if (playerInput == "quit")
        {
            menu::quit();
        }
        else
        {
            cout << "I don't understand you." << endl;
            pause();
        }
        while (!alienTurn)
        {
            for (auto &z : zombies)
            {
                clearScreen();
                z.attack();
            }
            for (auto &z : zombies)
            {
                z.move();
            }
            alienTurn = true;
        }
        while (all_of(zombies.begin(), zombies.end(), [](const Zombie &z)
                      { return z.getLife() == 0; }))
        {
            cout << "You have won the game!!!" << endl;
            pause();
            zombies.clear();
            exitMenu = false;
            gameToggle = false;
            return;
        }

    } while (alien.getLife() > 0);
    alien.display();
    hud();
    cout << "Game Over." << endl;
    pause();
    zombies.clear();
    exitMenu = false;
    gameToggle = false;
}

int main()
{
    srand(time(NULL));

    while (!exitGame)
    {

        while (!exitMenu)
        {
            menu::mainMenu(); // must loop to get back to menu after quitmenu
        }

        while (gameToggle)
        {
            clearScreen();

            if (newGame)
            {
                createPlayer();
            }
            else if (savedGame)
            {
                loadPlayer();
                break;
            }
            startGame();
        }
    }
}
