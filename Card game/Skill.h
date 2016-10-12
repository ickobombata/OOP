#ifndef SKILL_H
#define SKILL_H

#include "header.h"
class BattleField;
class Deck;
//prpbe
class Skill
{
protected:
    char* name;
    int attack;
    int health;
    bool canBeUsed;
public:
    Skill(const char* name , int attack , int health);
    Skill(const Skill& other);
    Skill& operator= (const Skill& other);
    virtual ~Skill();

    void setName(const char* name);

    void setAttack(int att) {attack = att;}
    void setHealth(int heal) {health = heal;}
    int getAttack() const { return attack;}
    int getHealth() const { return health;}
    bool getCanBeUsed() const { return canBeUsed; }
    void unFreeze() { this->canBeUsed = !canBeUsed ; }
    const char* getName() const { return name ;}

    virtual void printInfo() const ;
    virtual Skill* clone() const = 0;

    virtual void loadSpell(ifstream& input) = 0;
    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);
    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard) = 0;

    int getPosition(Deck& deck);
};

ostream& operator<< (ostream& out , const Skill& s); // using the output stream

#endif // SKILL_H
