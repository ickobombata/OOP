#ifndef ATTACKSKILL_H
#define ATTACKSKILL_H

#include "Skill.h"
class Deck;
class attackSkill : public Skill
{

public:
    attackSkill(const char* name ,int attack);
    attackSkill();

    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard);
    virtual void printInfo() const ;

    virtual Skill* clone() const { return new attackSkill(*this) ; }
    virtual void loadSpell(ifstream& input);
    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);
};

#endif // ATTAC


