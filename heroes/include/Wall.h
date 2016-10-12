#ifndef WALL_H
#define WALL_H

#include <Cell.h>


class Wall : public Cell
{
public:
    Wall();
    ~Wall();

    virtual void print() const;
};

#endif // WALL_H
