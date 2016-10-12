#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Deck.h"
#include "Player.h"

const size_t MAX_CARDS = 5;

class BattleField
{
private:
    Player p1;
    Player p2;

    Deck Player1;
    Deck Player2; // Deck is reasizable and adding and deletting is no problem

    Deck Graveyard;

    size_t round ; // on every "move" made by the two players (used card attack or using spell the round goes up by 1)
public:

    BattleField();
    ~BattleField();

    void fight();
public:
    void setRound(size_t round) { this->round = round ;} // validation
    size_t getRound() const { return this->round ; }
    void roundUp() { this->round += 1; }

    Deck& getPlayer1TableDeck() ;
    Deck& getPlayer2TableDeck() ;
    Deck& getGraveyard() ;
    Player& getPlayer1() ;
    Player& getPlayer2() ;
public:
    void chooseMode();
    void modeLoadGame();
    void modeNewGame();

    void playerPickCards(Deck& from ,Player& p , const char*);

    void playerPlay();
private:
};

#endif // BATTLEFIELD_H
