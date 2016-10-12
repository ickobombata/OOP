#include "BigFireBall.h"
#include "Deck.h"

BigFireBall::BigFireBall(const char* name , int attack)
    :Skill(name , attack , 0)
{
}
BigFireBall::BigFireBall()
    :Skill("" , 0 , 0)
{
}
BigFireBall::~BigFireBall()
{
}

void BigFireBall::use(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(enemy.getCountCards() <= 0)
        return;

    size_t midDmg = health / enemy.getCountCards();

    for(size_t i = 0 ; i < enemy.getCountCards(); i++)
    {
        enemy[i]->setHealth(enemy[i]->getHealth() - midDmg);
        if(enemy[i]->getHealth() <= 0)
        enemy.deleteCard(enemy[i]->getCardName());
    }
}

void BigFireBall::printInfo() const
{
    Skill::printInfo();
    cout << "group damage: "  << this->attack << endl;
}

void BigFireBall::loadSpell(ifstream& input)
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
    setAttack(value);
}

void BigFireBall::loadSpellBinary(ifstream& input)
{
    Skill::loadSpellBinary(input);

    int value = 0;

    input.read((char*) &value , sizeof(int));
    setAttack(value);
}
void BigFireBall::saveSpellBinary(ofstream& output)
{
    char temp = 'b';
    output.write((char*) &temp , sizeof(char));

    Skill::saveSpellBinary(output);

    output.write((char*) &attack , sizeof(int));
}
