#include "SpellFactory.h"

SpellFactory::SpellFactory()
{
    //ctor
}

SpellFactory::~SpellFactory()
{
    //dtor
}

Skill* SpellFactory::giveMeSkill(char code)
{
    switch(code)
        {
            case 'a':{
                return new attackSkill;
            }
            case 'b':{
                return new BigFireBall;
            }
            case 'd':{
                return new dispelSkill;
            }
            case 'h':{
                return new healingSkill;
            }
            case 'p':{
                return new postponeSkill;
            }
            case 't':{
                return new TeamHealing;
            }
            default:
                {
                    return NULL;
                }
        }
}
