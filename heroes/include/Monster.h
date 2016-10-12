#ifndef MONSTER_H
#define MONSTER_H

#include <Character.h>


class Monster : public Character
{
private:

public:
    Monster();
    ~Monster();

    virtual void print() const;
};

#endif // MONSTER_H
