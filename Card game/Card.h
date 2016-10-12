#pragma once
#include <iostream>
#include "header.h"
class Deck;
class BattleField;
#include "attackSkill.h"
#include "BigFireBall.h"
#include "dispelSkill.h"
#include "healingSkill.h"
#include "postponeSkill.h"
#include "TeamHealing.h"
#include "SpellFactory.h"

// Class card
// in public : default constuctor and constructor with arguments
// to enable creating card with nice name and attack,health
// Destructor to delete the dinamicly created memory
// operator= i use it later on when i shift the cards and maybe some other place
// copy construcot also get and set mhetods to enable the user to change att health and so on
// the private functions are help functions like to copy delete and to
// recalculate the Energy because everytime attack or health is changed
// 100 % that the energy will be changed too
const size_t MAX_HEALTH = 4000;
const size_t MAX_CARD_ENERGY = 100;
const size_t MAX_DAMAGE = 1000;

class Card
{
private:
    char *cardName;
    int attack;
    int health;
    double energy;
    int maxHealth;
    int canBeUsed ; // if 0 you can use if > you cant every round we go canBeUsed--

    int countSkills;
    Skill **skill;
public:
    Card();
    Card(char * cardName , int attack = 0 , int health = 0 );
    Card(const Card& other);
    Card & operator= (const Card & other);
    virtual ~Card();

    virtual Card* clone() const = 0;
public:
    bool operator== (const Card & other) const;
    bool operator!= (const Card & other) const;
    const Card & operator+= (int x);
    const Card & operator-= (int x);
    Skill* operator[] (const int index) const;
    const Skill* operator[] (const int index) ;
public:
    const char* getCardName() const;
    int getAttack() const;
    int getHealth() const ;
    int getCanBeUsed() const { return canBeUsed ;}
    double getEnergy() const ;
    void setCardName(const char*);
    void setAttack(int);
    void setHealth(int);
    void setCanBeUsed(int n)  { canBeUsed = n;}
    void reduceCanBeUsed() { canBeUsed-- ;}

    int getCountSkills() const { return this->countSkills;}
    void setCountSkills( int x) { countSkills = x ;}

    void printCard() const;
    void printSkills() const;
    //unsafeSet is called cuz i use it like a help function (it's safe in it's own way
    void unsafeSet(const char * cardName , int attack , int health );
    void recalculateEngergy();

    // skills stuff
    void addSkill(const Skill& other);

    virtual void loadCard(ifstream& input) = 0;
    virtual void loadCardBinary(ifstream& input);
    virtual void saveCardBinary(ofstream& output);

    virtual int cardAttack(Deck& mine , Deck& enemy , Deck& graveyard);
    bool spellAttack(Deck& mine , Deck& enemy , Deck& graveyard);
    int pureAttack(Deck& enemies);
    bool isGuard(Deck& deck);
private:
    void unsafeCopy(const Card &other);
    void unsafeDeleteName();
    bool unsafeCreate(int length);
    void createSkills();
    void freeSkills();
};

ostream& operator<< (ostream& out , const Card& c); // using the output stream
istream& operator>> (istream& in , Card& c);// using the input stream
