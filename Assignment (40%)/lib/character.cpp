#include "character.hpp"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

extern Alien alien;
extern vector<Zombie> zombies;
extern Zombie zombie;
extern int clearScreen();
extern int pause();

Alien::Alien(Board *board, int x, int y, int life, int attack) : x_(x), y_(y), life_(life), attack_(attack), board_(board) {}

void Alien::leaveTrail() {
    board_->setObject(x_, y_, trail_);
}

void Alien::moveUp() {
    heading_ = '^';
    while (y_ <= board_->getDimY()) {
        if (board_->getObject(x_, y_) == 'r') {
            char underRock = hitRock();
            board_->setObject(x_, y_, underRock);
            y_--;
            display();
            cout << "Alien hit a rock!" << endl;
            switch (underRock) {
                case 'h':
                    cout << "Alien found a health pack beneath the rock." << endl;
                    break;
                case 'p':
                    cout << "Alien found a pod beneath the rock." << endl;
                    break;
                case '>':
                case '<':
                case '^':
                case 'v':
                    cout << "Alien found an arrow beneath the rock.\n\n";
                    break;
                default:
                    cout << "Alien found nothing beneath the rock.\n\n";
                    break;
            }   
            pause();
            return;
        }
        else if (board_->getObject(x_, y_) == 'p') {
            hitPod();
        }
        else if (board_->getObject(x_, y_) == 'h') {
            hitHealth();
        }
        else if (board_->getObject(x_, y_) == 't') {
            hitTrap();
            return;
        }
        else if (board_->getObject(x_, y_) == 'Z') {
            y_--;
            hitZombie(x_, y_+1);
            return;
        }
        else if (board_->getObject(x_, y_) == '<') {
            hitArrow();
            moveLeft();
            return;
        }
        else if (board_->getObject(x_, y_) == '>') {
            hitArrow();
            moveRight();
            return;
        }
        else if (board_->getObject(x_, y_) == 'v') {
            hitArrow();
            moveDown();
            return;
        }
        else if (board_->getObject(x_, y_) == '^') {
            hitArrow();
            moveUp();
            return;
        }
        leaveTrail();
        y_++;
    }
    y_--;
    heading_ = '\0';
    display();
    cout << "Alien hit the border." << endl;
    pause();
}

void Alien::moveDown() {
    heading_ = 'v';
    while (y_ >= 1) {
        if (board_->getObject(x_, y_) == 'r') {
            char underRock = hitRock();
            board_->setObject(x_, y_, underRock);
            y_++;
            display();
            cout << "Alien hit a rock!" << endl;
            switch (underRock) {
                case 'h':
                    cout << "Alien found a health pack beneath the rock." << endl;
                    break;
                case 'p':
                    cout << "Alien found a pod beneath the rock." << endl;
                    break;
                case '>':
                case '<':
                case '^':
                case 'v':
                    cout << "Alien found an arrow beneath the rock.\n\n";
                    break;
                default:
                    cout << "Alien found nothing beneath the rock.\n\n";
                    break;
            }   
            pause();
            return;
        }
        else if (board_->getObject(x_, y_) == 'p') {
            hitPod();
        }
        else if (board_->getObject(x_, y_) == 'h') {
            hitHealth();
        }
        else if (board_->getObject(x_, y_) == 't') {
            hitTrap();
            return;
        }
        else if (board_->getObject(x_, y_) == 'Z') {
            y_++;
            hitZombie(x_, y_-1);
            return;
        }
        else if (board_->getObject(x_, y_) == '<') {
            hitArrow();
            moveLeft();
            return;
        }
        else if (board_->getObject(x_, y_) == '>') {
            hitArrow();
            moveRight();
            return;
        }
        else if (board_->getObject(x_, y_) == 'v') {
            hitArrow();
            moveDown();
            return;
        }
        else if (board_->getObject(x_, y_) == '^') {
            hitArrow();
            moveUp();
            return;
        }
        leaveTrail();
        y_--;
    }
    y_++;
    heading_ = '\0';
    display();
    cout << "Alien hit the border." << endl;
    pause();
}

void Alien::moveLeft() {
    heading_ = '<';
    while (x_ >= 1) {
        if (board_->getObject(x_, y_) == 'r') {
            char underRock = hitRock();
            board_->setObject(x_, y_, underRock);
            x_++;
            display();
            cout << "Alien hit a rock!" << endl;
            switch (underRock) {
                case 'h':
                    cout << "Alien found a health pack beneath the rock." << endl;
                    break;
                case 'p':
                    cout << "Alien found a pod beneath the rock." << endl;
                    break;
                case '>':
                case '<':
                case '^':
                case 'v':
                    cout << "Alien found an arrow beneath the rock.\n\n";
                    break;
                default:
                    cout << "Alien found nothing beneath the rock.\n\n";
                    break;
            }   
            pause();
            return;
        }
        else if (board_->getObject(x_, y_) == 'p') {
            hitPod();
        }
        else if (board_->getObject(x_, y_) == 'h') {
            hitHealth();
        }
        else if (board_->getObject(x_, y_) == 't') {
            hitTrap();
            return;
        }
        else if (board_->getObject(x_, y_) == 'Z') {
            x_++;
            hitZombie(x_-1, y_);
            return;
        }
        else if (board_->getObject(x_, y_) == '<') {
            hitArrow();
            moveLeft();
            return;
        }
        else if (board_->getObject(x_, y_) == '>') {
            hitArrow();
            moveRight();
            return;
        }
        else if (board_->getObject(x_, y_) == 'v') {
            hitArrow();
            moveDown();
            return;
        }
        else if (board_->getObject(x_, y_) == '^') {
            hitArrow();
            moveUp();
            return;
        }
        leaveTrail();
        x_--;
    }
    x_++;
    heading_ = '\0';
    display();
    cout << "Alien hit the border." << endl;
    pause();
}

void Alien::moveRight() {
    heading_ = '>';
    while (x_ <= board_->getDimX()) {
        if (board_->getObject(x_, y_) == 'r') {
            char underRock = hitRock();
            board_->setObject(x_, y_, underRock);
            x_--;
            display();
            cout << "Alien hit a rock!" << endl;
            switch (underRock) {
                case 'h':
                    cout << "Alien found a health pack beneath the rock." << endl;
                    break;
                case 'p':
                    cout << "Alien found a pod beneath the rock." << endl;
                    break;
                case '>':
                case '<':
                case '^':
                case 'v':
                    cout << "Alien found an arrow beneath the rock.\n\n";
                    break;
                default:
                    cout << "Alien found nothing beneath the rock.\n\n";
                    break;
            }   
            pause();
            return;
        }
        else if (board_->getObject(x_, y_) == 'p') {
            hitPod();
        }
        else if (board_->getObject(x_, y_) == 'h') {
            hitHealth();
        }
        else if (board_->getObject(x_, y_) == 't') {
            hitTrap();
            return;
        }
        else if (board_->getObject(x_, y_) == 'Z') {
            x_--;
            hitZombie(x_+1, y_);
            return;
        }
        else if (board_->getObject(x_, y_) == '<') {
            hitArrow();
            moveLeft();
            return;
        }
        else if (board_->getObject(x_, y_) == '>') {
            hitArrow();
            moveRight();
            return;
        }
        else if (board_->getObject(x_, y_) == 'v') {
            hitArrow();
            moveDown();
            return;
        }
        else if (board_->getObject(x_, y_) == '^') {
            hitArrow();
            moveUp();
            return;
        }
        leaveTrail();
        x_++;
    }
    x_--;
    heading_ = '\0';
    display();
    cout << "Alien hit the border." << endl;
    pause();
}

void Alien::hitPod() {
    cout << "Alien hits a pod." << endl;

    int id, nearestZombieX, nearestZombieY;
    int damage = 10;
    int minDistance = board_->getDimY() + board_->getDimX();  // initialize to a large value

    for (int i = 1; i <= board_->getDimY(); i++) {
        for (int j = 1; j <= board_->getDimX(); j++) {
            if (board_->getObject(j, i) == 'Z') {
                int distance = abs(i - getX()) + abs(j - getY());
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestZombieY = i;
                    nearestZombieX = j;
                }
            }
        }
    }
    
    if (minDistance == board_->getDimY() + board_->getDimX()) {
        display();
        cout << "No zombie found." << endl;
        pause();
    } 
    else {
        // inflict 10 damage to nearest zombie
        for (auto& z : zombies) {
        if (z.getX() == nearestZombieX && z.getY() == nearestZombieY) {
            id = z.getID();
            cout << id << endl;
            z.setLife(damage);
            //life = z.getLife();
            //cout << life << endl;
            }
        }
        display();
        cout << "Alien inflicts 10 damage to Zombie " << id << " at (" << nearestZombieX << "," << nearestZombieY << ")" << endl;
        pause();
    }
}

char Alien::hitRock() {
    char object;
    char objects[] = {' ', ' ', ' ', ' ', ' ', 'h', 'p', '<', '>', 'v', '^'};
    object = objects[rand() % 11];
    return object;
}

void Alien::hitArrow() {
    attack_ += 20;
    display();
    cout << "Alien finds an arrow.\n"
            "Alien's attack is increased by 20." << endl;
    pause();
}

void Alien::hitHealth() {
    life_ += 20;
    display();
    cout << "Health increased by +20" << endl;
    pause();
}

void Alien::hitTrap() {
    life_ -= 10;
    display();
    cout << "Alien fell into a trap.\n"
            "Alien's health is decreased by 10." << endl;
    pause();
} 

void Alien::hitZombie(int x, int y) {
    int id, life;
    for (auto& z : zombies) {
        if (z.getX() == x && z.getY() == y) {
            id = z.getID();
            z.setLife(attack_);
            life = z.getLife();
        }
    }
    display();
    cout << "Alien attacks Zombie " << id << "\n"
            "Zombie " << id << " receives a damage of " << getAttack() << endl;
    if (life == 0) {
        cout << "Zombie " << id << " has died." << endl;
        board_->setObject(x, y, ' ');
        zombies.erase(zombies.begin() + id-1);
        pause();
        switch(heading_) {
            case '<':
                moveLeft();
                break;
            case '>':
                moveRight();
                break;
            case 'v':
                moveDown();
                break;
            case '^':
                moveUp();
                break;
        }
    }
    else {
        cout << "Zombie " << id << " is still alive." << endl;
        pause();
    }
}

void Alien::setColumn(int x) {
      x_ = x;
}

void Alien::setRow(int y) {
      y_ = y;
}

int Alien::getX() const {
    return x_;
}

int Alien::getY() const {
    return y_;
}

int Alien::getLife() const {
    return life_;
}

int Alien::getAttack() const {
    return attack_;
}

void Alien::setLife(int &attack) {
    life_ -= attack;
    if (life_ < 0) {
        life_ = 0;
    }
}

void Alien::setHealth(int health) {
    life_ = health;
}

void Alien::resetAttack() {
    attack_ = 0;
}

char Alien::getHeading() const {
    return heading_;
}

void Alien::display() const {
    clearScreen();
    board_->setObject(x_, y_, 'A');
    board_->display();
    cout << "Alien position: (" << x_ << ", " << y_ << ")" << endl;
}

Zombie::Zombie() {}

void Zombie::setAttribute(int row, int column, int id, Board *board) {
    board_ = board;
    bool duplicate;
    do {
        x_ = rand() % column + 1;
        y_ = rand() % row + 1;
        if (board_->getObject(x_, y_) == 'Z' || (x_ == (column+2)/2 && y_ == (row+2)/2)) {
            duplicate = true;
        }
        else {
            board_->setObject(x_, y_, 'Z');
            duplicate = false;
        }
    } while (duplicate);
    id_ = id;
    life_ = 50 + rand() % 50;
    range_ = rand() % 5 + 1;
    attack_ = rand() % 10 + 10;
}

int Zombie::getID() const {
    return id_;
}

int Zombie::getLife() const {
    return life_;
}

int Zombie::getRange() const {
    return range_;
}

int Zombie::getAttack() const {
    return attack_;
}

void Zombie::setX(int &x) {
    x_ = x;
}

void Zombie::setY(int &y) {
    y_ = y;
}

void Zombie::setID(int &id) {
    id_ = id;
}

void Zombie::setLife(int &attack) {
    life_ -= attack;
    if (life_ < 0) {
        life_ = 0;
    }
}
void Zombie::setBoard(Board *board) {
    board_ = board;
    board_->setObject(x_, y_, 'Z');
}

void Zombie::setRange(int &range) {
    range_ = range;
}

void Zombie::setHealth(int &health) {
    life_ = health;
}

void Zombie::setAttack(int &attack) {
    attack_ = attack;
}

void Zombie::attack() {
    int x;
    int y;
    int count;
    // The person that wrote this is too lazy to implement A* search algo
    // North
    count = 0;
    for (y = y_; y <= board_->getDimY(); y++) {
        if (board_->getObject(x_, y) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 1;
    }
    // Northeast
    count = 0;
    for (x = x_, y = y_; x <= board_->getDimX() && y <= board_->getDimY(); x++, y++) {
        if (board_->getObject(x, y) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 2;
    }
    // East
    count = 0;
    for (x = x_; x <= board_->getDimX(); x++) {
        if (board_->getObject(x, y_) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 1;
    }
    // Southeast
    count = 0;
    for (x = x_, y = y_; x <= board_->getDimX() && y >= 1; x++, y--) {
        if (board_->getObject(x, y) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 2;
    }
    // South
    count = 0;
    for (y = y_; y >= 1; y--) {
        if (board_->getObject(x_, y) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 1;
    }
    // Southwest
    count = 0;
    for (x = x_, y = y_; x >= 1 && y >= 1; x--, y--) {
        if (board_->getObject(x, y) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 2;
    }
    // West
    count = 0;
    for (x = x_; x >= 1; x--) {
        if (board_->getObject(x, y_) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 1;
    }
    // Northwest
    count = 0;
    for (x = x_, y = y_; x >= 1 && y <= board_->getDimY(); x--, y++) {
        if (board_->getObject(x, y) == 'A') {
            if (count > getRange()) {
                break;
            }
            alien.setLife(attack_);
            board_->display();
            cout << "Zombie " << id_ << " attacked alien with " << attack_ << " damage." << endl;
            pause();
            return;
        }
        count += 2;
    }
    board_->display();
    cout << "Zombie " << id_ << " is unable to attack Alien." << endl;
    pause();
}

void Zombie::move()
{
    // randomly select a new direction
    bool loop;
    int dir = rand() % 4;
    switch (dir)
    {
        case 0: // move up
            if (y_ < board_->getDimY())
            {
                board_->setObject(x_, y_, ' ');
                y_++;
                if (board_->getObject(x_, y_) == 'A' || board_->getObject(x_, y_) == 'Z') {
                    y_--;
                }
            }
            break;
        case 1: // move down
            if (y_ > 1)
            {
                board_->setObject(x_, y_, ' ');
                y_--;
                if (board_->getObject(x_, y_) == 'A' || board_->getObject(x_, y_) == 'Z') {
                    y_++;
                }
            }
            break;
        case 2: // move left
            if (x_ > 1)
            {
                board_->setObject(x_, y_, ' ');
                x_--;
                if (board_->getObject(x_, y_) == 'A' || board_->getObject(x_, y_) == 'Z') {
                    x_++;
                }
            }
            break;
        case 3: // move right
            if (x_ < board_->getDimX())
            {
                board_->setObject(x_, y_, ' ');
                x_++;
                if (board_->getObject(x_, y_) == 'A' || board_->getObject(x_, y_) == 'Z') {
                    x_--;
                }
            }
            break;
    }
    
    // update the board with the new position
    board_->setObject(x_, y_, 'Z');
}

void Zombie::moveUp()
{
    if (y_ < board_->getDimY())
    {
        board_->setObject(x_, y_, ' ');
        y_++;
    }
}

void Zombie::moveDown()
{
    if (y_ > 1)
    {
        board_->setObject(x_, y_, ' ');
        y_--;
    }
}

void Zombie::moveLeft()
{
    if (x_ > 1)
    {
        board_->setObject(x_, y_, ' ');
        x_--;
    }
}

void Zombie::moveRight()
{
    if (x_ < board_->getDimX())
    {
        board_->setObject(x_, y_, ' ');
        x_++;
    }
}

int Zombie::getX() const
{
    return x_;
}

int Zombie::getY() const
{
    return y_;
}


void Zombie::display() const
{
    board_->setObject(x_, y_, 'Z');
    board_->display();
}
