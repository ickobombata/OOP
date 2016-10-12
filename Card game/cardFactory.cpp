#include "cardFactory.h"

cardFactory::cardFactory()
{
    //ctor
}

cardFactory::~cardFactory()
{
    //dtor
}

Card* cardFactory::giveMeCard(char code)
{
    switch(code)
    {
        case 'a' :{
            return new Assasin;
        }
        case 'g' :{
            return new Guard;
        }
        default:
            return NULL;
    }
}
