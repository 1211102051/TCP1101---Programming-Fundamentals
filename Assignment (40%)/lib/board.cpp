#include "board.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

Board::Board(int dimX, int dimY) : dimX_(dimX), dimY_(dimY) {}

void Board::setDimX(int x) {
    dimX_ = x;
}

void Board::setDimY(int y) {
    dimY_ = y;
}

int Board::getDimX() const {
    return dimX_;
}

int Board::getDimY() const {
    return dimY_;
}

void Board::init(int dimX, int dimY) {
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'p', 'r', 'h', 't', '<', '>', '^', 'v'};
    int noOfObjects = 16; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void Board::display() const
{

    for (int i = 0; i < dimY_; ++i)
    {
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY_ - i);
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

char Board::getObject(int x, int y) const
{
    return map_[dimY_ - y][x - 1];
}

void Board::setObject(int x, int y, char z)
{
    map_[dimY_ - y][x - 1] = z;
}

void Board::resetTrail() {
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', '>', 'v', '^', 'h', 'p', 't'};
    for (int i = 1; i <= dimX_; ++i) {
        for (int j = 1; j <= dimY_; ++j) {
            if (getObject(i, j) == '*') {
                setObject(i, j, objects[rand() % 14]);
            }
        }
    }
}
