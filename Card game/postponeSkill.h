#ifndef POSTPONESKILL_H
#define POSTPONESKILL_H

#include "Skill.h"
class Deck;
class postponeSkill : public Skill
{
private :
    int postponeRounds;
public:
    postponeSkill(const char* name , int postponeRounds);
    postponeSkill();
    ~postponeSkill();

    void setPostpone(int pos) { postponeRounds = pos ;}
    int getPostponeRounds() const { return postponeRounds;}

    virtual void use(Deck& mine , Deck& enemy , Deck& graveyard);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new postponeSkill(*this) ;}
    virtual void loadSpell(ifstream& input);
    virtual void loadSpellBinary(ifstream& input);
    virtual void saveSpellBinary(ofstream& output);
};

#endif // POSTPONESKILL_H

