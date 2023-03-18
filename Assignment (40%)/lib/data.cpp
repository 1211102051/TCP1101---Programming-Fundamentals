#include "data.hpp"
#include "character.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern Board board;
extern vector<Zombie> zombies;
extern Zombie zombie;
extern Alien alien;

extern int pause();
extern int clearScreen();

void saveGame() {
    Board *ptrBoard = &board;
    Alien *ptrAlien = &alien;
    vector<Zombie> *ptrZombies = &zombies;
    string filename;

    cout << "Enter file name: ";
    cin >> filename;
    ofstream save;
    std::string target = "./save/" + filename;
    save.open(target);

    // Save board dimensions
    save << ptrBoard->getDimX() << " " << ptrBoard->getDimY() << std::endl;

    // Save alien attributes
    save << ptrAlien->getX() << " " << ptrAlien->getY() << " " << ptrAlien->getLife() << std::endl;

    // Save zombie count and coordinates
    save << zombies.size() << std::endl;
    for (const auto& zombie : zombies) {
        save << zombie.getID() << " " << zombie.getX() << " " << zombie.getY() << " " << zombie.getLife() << " " << zombie.getAttack() << " " << zombie.getRange() << std::endl;
    }

    save.close();
}

void loadGame() {
    bool loop;
    string filename;
    int zombiecount;

    do {
        cout << "Enter the name of the saved game file: ";
        cin >> filename;
        std::string target = "./save/" + filename;
        ifstream inFile(target);
        if (inFile.is_open()) {
            // Read board dimensions
            int row, column;
            inFile >> column >> row;
            board.setDimY(row);
            board.setDimX(column);
            board.init(column, row);

            // Read alien coordinates and life
            int x, y, life;
            inFile >> x >> y >> life;
            alien.setRow(y);
            alien.setColumn(x);
            alien.setHealth(life);

            // Read zombie count and coordinates
            inFile >> zombiecount;
            zombies.clear();
            for (int i = 0; i < zombiecount; i++) {
                int id, x, y, life, attack, range;
                inFile >> id >> x >> y >> life >> attack >> range;
                zombie.setID(id);
                zombie.setX(x);
                zombie.setY(y);
                zombie.setHealth(life);
                zombie.setAttack(attack);
                zombie.setRange(range);
                zombie.setBoard(&board);
                zombies.push_back(zombie);
            }

            // Close the file
            inFile.close();

            cout << "Game loaded from file " << filename << endl;
            pause();
            loop = false;
        }
        else {
            cout << "Unable to locate file " << filename << "\n"
                    "Please enter the correct save filename." << endl;;
            pause();
            loop = true;
            clearScreen();
        }
    } while (loop);
}
