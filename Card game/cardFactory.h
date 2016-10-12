#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Assasin.h"
#include "Guard.h"

class cardFactory
{
    public:
        cardFactory();
        ~cardFactory();

    Card* giveMeCard(char code);
};

#endif // CARDFACTORY_H
