#ifndef BOOTS_H
#define BOOTS_H

#include <Item.h>


class Boots : public Item
{
private:
    unsigned speed;
    unsigned dodge;
public:
    Boots();
    virtual ~Boots();
};

#endif // BOOTS_H
