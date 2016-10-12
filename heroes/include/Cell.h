#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell
{
private:

public:
    Cell();
    Cell(const Cell& other);
    virtual ~Cell();

    virtual void print() const = 0;
};

#endif // CELL_H
