#pragma once

#include <vector>

class Board
{
private:
    std::vector<std::vector<char>> map_;
    int dimX_, dimY_;

public:
    Board(int dimX, int dimY);
    void init(int dimX, int dimY);
    void display() const;
    void setDimX(int x);
    void setDimY(int y);
    int getDimX() const;
    int getDimY() const;
    char getObject(int x, int y) const;
    void setObject(int x, int y, char z);
    void resetTrail();
};
