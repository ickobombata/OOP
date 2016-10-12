#include "dispelSkill.h"
#include "Deck.h"

dispelSkill::dispelSkill(const char* name)
    : Skill(name , 0 , 0)
{

}
dispelSkill::dispelSkill()
    : Skill("" , 0 , 0)
{
}
dispelSkill::~dispelSkill()
{
    //dtor
}

void dispelSkill::use(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(mine.getCountCards() <= 0)
        return;

    size_t pos = getPosition(mine);

    mine[pos]->setCanBeUsed(0);
}
void dispelSkill::printInfo() const
{
    Skill::printInfo();
    cout << "dispel!" << endl;
}

void dispelSkill::loadSpell(ifstream& input)
{
    size_t nameLength;

    input >> nameLength;
    if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }

    char* tempName = new char[nameLength];
    input.get(tempName,nameLength);
    this->setName(tempName);
    delete [] tempName;

}

void dispelSkill::loadSpellBinary(ifstream& input)
{
    Skill::loadSpellBinary(input);

}
void dispelSkill::saveSpellBinary(ofstream& output)
{
    char temp = 'd';
    output.write((char*) &temp , sizeof(char));

    Skill::saveSpellBinary(output);
}
