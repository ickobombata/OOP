#include "TeamHealing.h"
#include "Deck.h"
TeamHealing::TeamHealing(const char* name ,int health)
    :Skill(name , 0 , health)
{
}

TeamHealing::TeamHealing()
    :Skill("" , 0 , 0)
{
}
TeamHealing::~TeamHealing()
{
}

void TeamHealing::use(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(mine.getCountCards() <= 0)
        return;
    size_t midHealth = health / mine.getCountCards();

    for(size_t i = 0 ; i < mine.getCountCards(); i++)
    {
        mine[i]->setHealth(mine[i]->getHealth() + midHealth);
    }
}
void TeamHealing::printInfo() const
{
    Skill::printInfo();
    cout << "Team health: " << health << endl;
}

void TeamHealing::loadSpell(ifstream& input)
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


void TeamHealing::loadSpellBinary(ifstream& input)
{
    Skill::loadSpellBinary(input);

    int value = 0;
    input.read((char*) &value , sizeof(int));
    setHealth(value);
}
void TeamHealing::saveSpellBinary(ofstream& output)
{
    char temp = 't';
    output.write((char*) &temp , sizeof(char));

    Skill::saveSpellBinary(output);

    output.write((char*) &health , sizeof(int));
}
