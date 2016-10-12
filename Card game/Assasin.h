#ifndef ASSASIN_H
#define ASSASIN_H

#include "Card.h"
class Deck;

class Assasin : public Card
{
public:
    Assasin(char * cardName , int attack = 0 , int health = 0 );
    Assasin();
    virtual Card* clone() const { return new Assasin(*this);}

    virtual void loadCard(ifstream& input);
    virtual void saveCardBinary(ofstream& output);
    virtual int cardAttack(Deck& mine , Deck& enemy , Deck& graveyard);
};

#endif // ASSASIN_H
