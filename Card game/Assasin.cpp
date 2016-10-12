#include "Assasin.h"
#include "Deck.h"

Assasin::Assasin(char * cardName , int attack , int health)
    : Card(cardName , attack , health)
{

}
Assasin::Assasin()
{
}
///
/// attacking
///
int Assasin::cardAttack(Deck& mine , Deck& enemy , Deck& graveyard)
{
    Card::cardAttack(mine , enemy , graveyard);

// if there is guard We will attacking him else we will return some dmg to the heroe
    for(size_t i = 0 ; i < enemy.getCountCards() ; i++)
    {
        Guard* g = dynamic_cast<Guard*>(enemy[i]);
        if(g)
        {
            g->setHealth(g->getHealth() - getAttack()*1.5);
            return 0;
        }
    }
    return getAttack()*1.5;

}
/// loading
/// and Saving
///
void Assasin::loadCard(ifstream& input)
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
    this->setCardName(tempName);
    delete [] tempName;

    size_t value;
    input >> value;
    if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }
    setAttack(value);

    input >> value ;
    if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }
    setHealth(value);

    SpellFactory sF;
    char spellCode = '!';

    input >> spellCode;
    if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }

    while(spellCode != 'E')
    {
        input >> spellCode;
        if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }
        if(spellCode == '|')
            input >> spellCode;
        if(!input)
        {//NOTNOT
            cout << "File problem" << endl;
            return;
        }

        if(spellCode == 'E')
            break;

        Skill* tempSkill = sF.giveMeSkill(spellCode);
        tempSkill->loadSpell(input);

        addSkill(*tempSkill);
        delete tempSkill;
    }
}
void Assasin::saveCardBinary(ofstream& output)
{
    char assasinIndex = 'g';

    output.write((char*) &assasinIndex , sizeof(char));

    Card::saveCardBinary(output);
}
