#include "postponeSkill.h"
#include "Deck.h"

postponeSkill::postponeSkill(const char* name , int postponeRounds)
    :Skill(name , 0 , 0 )
{
    setPostpone(postponeRounds);
}
postponeSkill::postponeSkill()
    :Skill("" , 0 , 0 )
{
}


postponeSkill::~postponeSkill()
{
}

void postponeSkill::use(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(enemy.getCountCards() <= 0)
        return;

    size_t pos = getPosition(enemy);

    enemy[pos]->setCanBeUsed(enemy[pos]->getCanBeUsed() + 1);
}
void postponeSkill::printInfo() const
{
    Skill::printInfo();
    cout << "Postpone: " << this->postponeRounds << endl;
}

void postponeSkill::loadSpell(ifstream& input)
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

    int value;
    input >> value;
    if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }
    setPostpone(value);
}

void postponeSkill::loadSpellBinary(ifstream& input)
{
    Skill::loadSpellBinary(input);

    int value = 0;
    input.read((char*) &value , sizeof(int));
    setPostpone(value);
}
void postponeSkill::saveSpellBinary(ofstream& output)
{
    char temp = 'p';
    output.write((char*) &temp , sizeof(char));

    Skill::saveSpellBinary(output);
    output.write((char*) &postponeRounds , sizeof(int));
}
