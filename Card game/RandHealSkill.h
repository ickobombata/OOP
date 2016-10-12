#ifndef RANDHEALSKILL_H
#define RANDHEALSKILL_H

#include "Skill.h"

class RandHealSkill : public Skill
{
    private:
        int heal;
    public:
        RandHealSkill(const char* name ,BattleField& bf  , int attack , int position);
        ~RandHealSkill();

    virtual void use(BattleField& bf  , int * positions, int length);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new RandHealSkill(*this) ;}

};

#endif // RANDHEALSKILL_H
