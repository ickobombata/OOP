#include "Skill.h"
#include "BattleField.h"
#include "Deck.h"

Skill::Skill(const char* name , int attack , int health)
    :name(NULL) , canBeUsed(true)
{
    setAttack(attack);
    setHealth(health);
    this->name = new char[strlen(name)+1];
    strcpy(this->name , name );
}

Skill::Skill(const Skill& other)
{
    this->attack = other.getAttack();
    this->health = other.getHealth();
    this->canBeUsed = other.getCanBeUsed();

    this->name = new char[strlen(other.name)+1];
    strcpy(this->name , other.name );
}
Skill& Skill::operator= (const Skill& other)
{
    if(this != &other)
    {
        this->attack = other.getAttack();
        this->health = other.getHealth();
        this->canBeUsed = other.getCanBeUsed();
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name , other.name );
    }
}
Skill::~Skill()
{
    delete [] name;
}

void Skill::printInfo() const
{
    cout << "Spell Name: " << this->name << "     ";
}

ostream& operator<< (ostream& out , const Skill& c)
{
    if(!out)
    {
        cout << "Something happend\n";
        return out;
    }
    out << c.getName()  << endl;
    out << c.getAttack()    << endl;
    out << c.getHealth()    << endl;

    return out;
}

void Skill::setName(const char* name)
{
    delete [] this->name;

    this->name = new char[strlen(name)+1];

    strcpy(this->name , name);
}


void Skill::loadSpellBinary(ifstream& input)
{
    size_t value;

    input.read((char*) &value , sizeof(size_t));

    char* tempName = new char[value+1];
    input.read((char*) tempName , value*sizeof(char));
    tempName[value] = '\0';
    setName(tempName);
    delete [] tempName;

}
void Skill::saveSpellBinary(ofstream& output)
{
    size_t nameLength = strlen(this->getName());

    output.write((char*) &nameLength , sizeof(size_t));
    output.write((char*) name , nameLength*sizeof(char));

}

int Skill::getPosition(Deck& deck)
{
    size_t deckLength = deck.getCountCards() ;

    deck.printDeck();
    size_t No ;
    cout << " Select whitch card to be affected !" << endl;

    do
    {
        cin.clear();
        cin.sync();

        cin >> No;

    }while(!cin || No >= deckLength );

    return No;
}
