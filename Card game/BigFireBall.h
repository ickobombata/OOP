#ifndef BIGFIREBALL_H
#define BIGFIREBALL_H

#include "Skill.h"
class Deck;
class BigFireBall : public Skill
{
    public:
        BigFireBall(const char* name , int attack);
        BigFireBall();
        ~BigFireBall();

    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new BigFireBall(*this) ;}
    virtual void loadSpell(ifstream& input);
    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);
};

#endif // BIGFIREBALL_H
