#ifndef HEALINGSKILL_H
#define HEALINGSKILL_H

#include "Skill.h"
class Deck;

class healingSkill : public Skill
{
    public:
        healingSkill(const char* name ,int health);
        healingSkill();
        ~healingSkill();

    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new healingSkill(*this) ;}
    virtual void loadSpell(ifstream& input);
    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);
};

#endif // HEALINGSKILL_H

