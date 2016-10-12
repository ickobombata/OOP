#include "Guard.h"

Guard::Guard(char * cardName , int attack , int health)
            : Card(cardName , attack , health)
{
    //ctor
}

Guard::Guard()
{

}///
/// attacking
///
int Guard::cardAttack(Deck& mine , Deck& enemy , Deck& graveyard)
{
    return Card::cardAttack(mine , enemy , graveyard);
}
/// loading
/// and Saving
///

void Guard::loadCard(ifstream& input)
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

    char spellCode = '!';
    SpellFactory sF;

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
void Guard::saveCardBinary(ofstream& output)
{
    char guardIndex = 'g';

    output.write((char*) &guardIndex , sizeof(char));

    Card::saveCardBinary(output);
}
