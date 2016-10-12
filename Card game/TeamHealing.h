#ifndef TEAMHEALING_H
#define TEAMHEALING_H

#include "Skill.h"
class Deck;
// passive skill
class TeamHealing : public Skill
{
    public:
        TeamHealing(const char* name ,int health);
        TeamHealing();
        ~TeamHealing();

    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new TeamHealing(*this) ;}
    virtual void loadSpell(ifstream& input);
    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);

    void addHealth(int* positions , Deck& d);
};

#endif // TEAMHEALING_H
