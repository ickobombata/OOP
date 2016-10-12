#ifndef SPELLFACTORY_H
#define SPELLFACTORY_H

#include "attackSkill.h"
#include "BigFireBall.h"
#include "dispelSkill.h"
#include "healingSkill.h"
#include "postponeSkill.h"
#include "TeamHealing.h"

class SpellFactory
{
    public:
        SpellFactory();
        ~SpellFactory();

    Skill* giveMeSkill(char code) ;
};

#endif // SPELLFACTORY_H
