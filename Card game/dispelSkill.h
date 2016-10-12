#ifndef DISPELSKILL_H
#define DISPELSKILL_H

#include "Skill.h"
class Deck;

class dispelSkill : public Skill
{
    public:
        dispelSkill(const char* name);
        dispelSkill();
        ~dispelSkill();

    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new dispelSkill(*this) ;}

    virtual void loadSpell(ifstream& input);

    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);
};

#endif // DISPELSKILL_H
