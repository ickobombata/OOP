#include "attackSkill.h"
#include "Deck.h"

attackSkill::attackSkill(const char* name , int attack)
    :Skill(name , attack , 0)
{
}
attackSkill::attackSkill()
    :Skill("" , 0 , 0)
{
}
void attackSkill::use(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(enemy.getCountCards() <= 0)
        return;
    size_t pos = getPosition(enemy);

    enemy[pos]->setHealth(enemy[pos]->getHealth() - this->attack);
    if(enemy[pos]->getHealth() <= 0)
        enemy.deleteCard(enemy[pos]->getCardName());
}

void attackSkill::printInfo() const
{
    Skill::printInfo();
    cout << "damage: " << this->attack << endl;
}

void attackSkill::loadSpell(ifstream& input)
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
    setName(tempName);
    delete [] tempName;

    int value;
    input >> value;
    if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }
    setAttack(value);
}

void attackSkill::loadSpellBinary(ifstream& input)
{
    Skill::loadSpellBinary(input);

    int value = 0;
    input.read((char*) &value , sizeof(size_t));
    setAttack(value);
}
void attackSkill::saveSpellBinary(ofstream& output)
{
    char temp = 'a';
    output.write((char*) &temp , sizeof(char));

    Skill::saveSpellBinary(output);

    output.write((char*) &attack , sizeof(size_t));
}
