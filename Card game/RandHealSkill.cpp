#include "RandHealSkill.h"

RandHealSkill::RandHealSkill(const char* name ,BattleField& bf  , int health ,int position)
    :Skill(name , 0 , health)
{
    heal = (rand() % 20) + 1;
    int temp[1] = {position};
    use(bf , temp, 1);
}

RandHealSkill::~RandHealSkill()
{
}

void RandHealSkill::use(BattleField& bf  , int * positions , int length)
{
        // for the cards in position i we reduce health
        if(heal < 3)
            bf( 2 , positions[0]) += health*heal; // it health so + health
}
void RandHealSkill::printInfo() const
{
    Skill::printInfo();
    cout << "passive healing: "<< heal % 100 << "%" << endl;
}
