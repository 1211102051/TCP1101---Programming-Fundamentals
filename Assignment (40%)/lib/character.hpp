#pragma once

#include "board.hpp"
#include <string>

class Alien
{
private:
    int x_, y_, life_, attack_;
    char heading_; // either '^', '>', '<' or 'v'
    Board *board_;
    char trail_ = '*';

public:
    Alien(Board *board, int x, int y, int life, int attack);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void hitPod();
    char hitRock();
    void hitArrow();
    void hitHealth();
    void hitTrap();
    void hitZombie(int x, int y);
    void setColumn(int x);
    void setRow(int y);
    int getX() const;
    int getY() const;
    int getLife() const;
    int getAttack() const;
    void setLife(int &attack);
    void setHealth(int health);
    void resetAttack();
    char getHeading() const;
    void display() const;
    void leaveTrail();
};

class Zombie
{
private:
    int x_, y_, id_, life_, range_, attack_;
    Board *board_;

public:
    Zombie();
    void setAttribute(int x, int y, int id, Board *board);
    int getID() const;
    int getLife() const;
    int getRange() const;
    int getAttack() const;
    void setX(int &x);
    void setY(int &y);
    void setID(int &id);
    void setLife(int &attack);
    void setBoard(Board *board);
    void setRange(int &range);
    void setHealth(int &health);
    void setAttack(int &attack);
    void attack();
    void move();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getX() const;
    int getY() const;
    void display() const;
};
