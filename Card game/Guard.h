#ifndef GUARD_H
#define GUARD_H

#include "Card.h"

class Guard : public Card
{
    public:
        Guard(char * cardName , int attack = 0 , int health = 0 );
        Guard();
        virtual Card* clone() const { return new Guard(*this);}

        virtual void loadCard(ifstream& input);
        virtual void saveCardBinary(ofstream& output);
        virtual int cardAttack(Deck& mine , Deck& enemy , Deck& graveyard);
};

#endif // GUARD_H
