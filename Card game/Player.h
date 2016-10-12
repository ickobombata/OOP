#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "header.h"

const size_t MAX_ENERGY = 100;

class Player : public Deck
{
    size_t hp ;
    size_t energy ;

    public:
        Player();
        ~Player();

    int yourTurnToPlay(Deck& ownTableCards , Deck& enemyTableCards , Deck& graveyard);

public:
    bool loadPlayerBinary();
    void savePlayerBinary();
private:
    const char* getTheFilePath() const;

private:
    Card* chooseCardToUse(Deck& ownTableCards) ;
    bool wannaPlaceCard();
    void placeCard(Deck&);

public:

    void setHp(int hp);
    void reduceHP(int hp);
    void setEnergy(int energy);
    void upEnergy(int energy);

    size_t getHp() const { return this->hp;}
    size_t getEnergy() const { return this->energy;}
};

#endif // PLAYER_H
