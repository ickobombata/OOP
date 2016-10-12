#include "CriticalSkill.h"

CriticalSkill::CriticalSkill(const char* name ,BattleField& bf  , int attack ,int position)
    :Skill(name , 0 , attack)
{
    this->critical = (rand() % 20) + 1 ;
    int temp[1] = {position};
    use(bf , temp, 1);
}

CriticalSkill::~CriticalSkill()
{
}

void CriticalSkill::use(BattleField& bf  , int * positions , int length)
{
        // for the cards in position i we reduce attack
        if(critical < 3)
            bf( 2 , positions[0]) -= attack*critical; // it attack so - attack
}

void CriticalSkill::printInfo() const
{
    Skill::printInfo();
    cout << "passive critical: " << critical % 100 << "%" << endl;
}
