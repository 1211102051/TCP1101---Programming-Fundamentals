#include "menus.hpp"
#include <iostream>
#include <cctype>

using namespace std;

// declared global variable from main
extern int row;
extern int column;
extern int zombiecount;
extern bool newGame;
extern bool exitMenu;
extern bool savedGame;
extern bool gameToggle;
extern int clearScreen();
extern int pause();

// the use of namespace to avoid name conflicts
namespace menu
{
    void quit()
    {
        bool loop = true;
        char choice;
        do
        {
            loop = false;
            cout << "Are you sure you want to quit? [Y/N]" << endl;
            cout << "Enter => ";
            cin >> choice;
            choice = tolower(choice);

            if (choice == 'y')
            {
                exit(1);
                break;
            }
            else if (choice == 'n')
            {
                exitMenu = false;
                return;
            }
            else
            {
                cout << "Wrong input, try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                pause();
                clearScreen();
                loop = true;
            }
        } while (loop);
    }

    void help()
    {
            // Print a table of commands and their descriptions
        cout << "Command | Description" << endl;
        cout << "--------|------------------------------------" << endl;
        cout << "up      | Move the alien up" << endl;
        cout << "down    | Move the alien down" << endl;
        cout << "left    | Move the alien left" << endl;
        cout << "right   | Move the alien right" << endl;
        cout << "arrow   | Switch the direction of an arrow object" << endl;
        cout << "        | on the game board" << endl;
        cout << "save    | Save the current game progress" << endl;
        cout << "load    | Load a previously saved game" << endl;
        cout << "quit    | Quit the game" << endl;
        pause();
    }

    void settingMenu(int row, int column, int zombiecount)
    {
        cout << "Default Game Settings" << endl;
        cout << "---------------------" << endl;
        cout << "Board Rows       :" << row << endl;
        cout << "Board Columns    :" << column << endl;
        cout << "Zombie Count     :" << zombiecount << endl;
        cout << "Please enter odd number digits of the Board rows and board columns" << endl;
    }

    void changeSettings(int &row, int &column, int &zombiecount)
    {
        bool odd;
        do
        {
            cout << "Board Settings" << endl;
            cout << "--------------" << endl;
            cout << "Board Rows => ";
            cin >> row;
            cout << "\nBoard Columns => ";
            cin >> column;
            cout << "\nZombie Settings" << endl;
            cout << "---------------" << endl;
            cout << "Zombie count => ";
            cin >> zombiecount;
            if (row % 2 == 0 || column % 2 == 0)
            {
                odd = false;
                cout << "\nPlease enter odd number for row and column.\n"
                     << endl;
                pause();
                clearScreen();
            }
            else
            {
                odd = true;
                cout << "\nSettings Updated.\n"
                     << endl;
                pause();
            }
        } while (!odd);
    }

    void mainMenu()
    {
        bool loop = true;
        int choice;

        do
        {
            clearScreen();
            cout << "-----------------------------\n"
                    "          Main Menu          \n"
                    "-----------------------------"
                 << endl;
            cout << "Please select an option:" << endl;
            cout << "1. New Game - Start a new game from the beginning" << endl;
            cout << "2. Load Game - Load a previously saved game" << endl;
            cout << "3. Quit - Exit the game" << endl;
            cout << "Enter your choice (1-3): ";

            int choice;
            cin >> choice;

            // will loop when user enter wrong number
            loop = false;
            switch (choice)
            {
            case 1:
                gameToggle = true;
                exitMenu = true;
                newGame = true;
                loop = false;
                break;
            case 2:
                gameToggle = true;
                savedGame = true;
                exitMenu = true;
                loop = false;
                break;

            case 3:
                exitMenu = true;
                quit();
                loop = false;
                break;
            default:
                cout << "Input not accepted." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                pause();
                loop = true;
                break;
            }
        } while (loop);
    }
}
