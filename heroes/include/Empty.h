#ifndef EMPTY_H
#define EMPTY_H

#include <Cell.h>


class Empty : public Cell
{
public:
    Empty();
    ~Empty();

    virtual void print() const;
};

#endif // EMPTY_H
