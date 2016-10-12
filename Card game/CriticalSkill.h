#ifndef CRITICALSKILL_H
#define CRITICALSKILL_H

#include "Skill.h"

class CriticalSkill : public Skill
{
    private:
        int critical;
    public:
        CriticalSkill(const char* name ,BattleField& bf  , int attack , int position);
        ~CriticalSkill();

    virtual void use(BattleField& bf  , int * positions, int length);
    virtual void printInfo() const ;
    virtual Skill* clone() const { return new CriticalSkill(*this) ;}

};

#endif // CRITICALSKILL_H
