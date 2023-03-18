#include "character.hpp"
#include "display.hpp"
#include <iostream>
#include <vector>

using namespace std;
extern int pause();
extern Board board;
extern Alien alien;
extern vector<Zombie> zombies;

void hud() {
    cout << "Alien   | Life[" << alien.getLife() << "] Attack[" << alien.getAttack() << "]\n";
    for (auto& z : zombies) {
        cout << "Zombie " << z.getID() << "| Life[" << z.getLife() << "] Attack["<< z.getAttack() << "] Range[" << z.getRange() << "]" << endl;
    }
}

void switchArrow() {
    int row;
    int column;
    char newArrow;
    bool loop;
    Board *ptrBoard = &board;
    do {
        cout << "Arrow's Row => ";
        cin >> row;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "\nArrow's Column => ";
        cin >> column;
        cin.clear();
        cin.ignore(1024, '\n');
        if (ptrBoard->getObject(column, row) == '<' || ptrBoard->getObject(column, row) == '>' || ptrBoard->getObject(column, row) == 'v' || ptrBoard->getObject(column, row) == '^'){
            loop = false;
        }
        else {
            cout << "\nArrow is not here" << endl;
            loop = true;
        }
    } while (loop);
    cout << "\nSwitch to => ";
    cin >> newArrow;
    if (!(newArrow == '<' || newArrow == '>' || newArrow == 'v' || newArrow == '^')) {
        cout << "That's not an arrow!" << endl;
        pause();
    }
    else {
        ptrBoard->setObject(column, row, newArrow);
        cout << "Changed Arrow!" << endl;
        pause();
    }
}
