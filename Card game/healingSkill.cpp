#include "healingSkill.h"
#include "Deck.h"

healingSkill::healingSkill(const char* name ,int health)
    :Skill(name , 0 , health)
{
}

healingSkill::healingSkill()
    :Skill("" , 0 , 0)
{
}
healingSkill::~healingSkill()
{
}

void healingSkill::use(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(mine.getCountCards() <= 0)
        return;

    size_t pos = getPosition(mine);

    mine[pos]->setHealth(mine[pos]->getHealth() + this->health);
}
void healingSkill::printInfo() const
{
    Skill::printInfo();
    cout << "healing: " << health << endl;
}

void healingSkill::loadSpell(ifstream& input)
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
    setHealth(value);
}

void healingSkill::loadSpellBinary(ifstream& input)
{
    Skill::loadSpellBinary(input);

    int value = 0;
    input.read((char*) &value , sizeof(int));
    setHealth(value);
}
void healingSkill::saveSpellBinary(ofstream& output)
{
    char temp = 'h';
    output.write((char*) &temp , sizeof(char));

    Skill::saveSpellBinary(output);

    output.write((char*) &health , sizeof(int));
}
