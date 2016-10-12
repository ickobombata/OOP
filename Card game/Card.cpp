#include "Card.h"
#include "Deck.h"
#include "BattleField.h"
///
/// Consturctors,Destructors , Copy constructors ..
///
Card::Card() : maxHealth(1000000) ,countSkills(0) , canBeUsed(0)
{
    if(unsafeCreate(10))
        strcpy(this->cardName , "//////////");
    setAttack(0);
    setHealth(0);

    createSkills();
}
Card::Card(char * cardName , int attack , int health ) : maxHealth(1000000) ,countSkills(0) ,canBeUsed(0)
{
    unsafeSet(cardName , attack , health);
    createSkills();
}
Card::~Card()
{
	unsafeDeleteName();
	freeSkills();
}
Card::Card(const Card& other)
{
    unsafeDeleteName();
    unsafeCopy(other);
}
///
/// opeators of Class Card
///
Card & Card::operator=(const Card & other)
{
    if(this != &other)
    {
        unsafeDeleteName();
        unsafeCopy(other);
    }
    return *this;
}
bool Card::operator== (const Card & other) const
{
    if(this->attack == other.attack &&
       this->health == other.health &&
       strcmp(this->cardName , other.cardName) == 0)
    {
        return 1;
    }
    return 0;
}
bool Card::operator!= (const Card & other) const
{
    return !(*this==other);
}
const Card & Card::operator+= (int x)
{
    if(this->health + x <= this->maxHealth)
    {
        this->health+= x;
    }
	else
	{
	 this->health = this->maxHealth;
	}
    return (*this);
}
const Card & Card::operator-= (int x)
{
    if(this->health - x >= 0)
    {
        this->health-= x;
    }
	else
	{
		this->health = 0;
	}
    return (*this);
}
Skill* Card::operator[] (const int index) const
{
    // if the index is posible to be allocated in the deck we return that pointer
    if(index > this->countSkills)
        cout << "index out of range" << endl;
    return this->skill[index];
}
const Skill* Card::operator[] (const int index)
{
    // the same as above only this time we return const Pointer
    if(index > this->countSkills)
        cout << "index out of range" << endl;
    return this->skill[index];
}
ostream& operator<< (ostream& out , const Card& c)
{
    if(!out)
    {
        cout << "Something happend\n";
        return out;
    }
    out << c.getCardName()  << endl;
    out << c.getAttack()    << endl;
    out << c.getHealth()    << endl;
    out << c.getEnergy()    << endl;

    c.printSkills();
    cout << endl;
    return out;
}
istream& operator>> (istream& in , Card& c)
{
    char buffer[100];
    in.getline(buffer , 100);
    if(!in)
    {
        cout << "Somethign happend\n";
        c.setCardName("//////////");
        c.setAttack(0);
        c.setHealth(0);
        c.recalculateEngergy();
        return in;
    }
    c.setCardName(buffer);
    int temp = 0;
    in >> temp;
    if(!in)
    {
        cout << "somethign happend\n";
        c.setCardName("//////////");
        c.setAttack(0);
        c.setHealth(0);
        c.recalculateEngergy();
        return in;
    }
    c.setAttack(temp);

    in >> temp;
    if(!in)
    {
        cout << "somethign happend\n";
        c.setCardName("//////////");
        c.setAttack(0);
        c.setHealth(0);
        c.recalculateEngergy();
        return in;
    }
    c.setHealth(temp);
    c.recalculateEngergy();
    return in;
}
///
/// Allocating and deleting memory methods of class Card
///
void Card::unsafeSet(const char * cardName , int attack , int health )
{
    setCardName(cardName);
    setAttack(attack);
    setHealth(health);
}
void Card::unsafeCopy(const Card& other)
{
    setAttack(other.attack);
    setHealth(other.health);
    setCountSkills(0);
    setCanBeUsed(0);

    setCardName(other.getCardName());

    createSkills();

    while(this->countSkills < other.getCountSkills())
    {
        skill[this->countSkills] = other[this->countSkills]->clone();
        this->countSkills++;
    }
}
void Card::unsafeDeleteName()
{
    if(this->cardName)
        delete [] this->cardName;
}
bool Card::unsafeCreate(int length)
{
    this->cardName = new(nothrow) char[length+1];
    if(!this->cardName)
    {
        cout << "Problem occured: Out of memory" << endl;
        return false;
    }
    return true;
}
void Card::createSkills()
{
    skill = new(nothrow) Skill*[3];
    if(!skill)
        cout << "No memory" << endl;

//    for(int i = 0 ; i < 3 ; i++)
//        skill[i] = NULL;
}
void Card::freeSkills()
{
    for(int i = 0 ; i < countSkills ; i++)
    {
        delete skill[i];
    }
    delete  [] skill ;
}
///
/// get and set metdhos of class Card
///
void Card::setCardName(const char * cardName)
{
    size_t lenght = strlen(cardName);
    if(unsafeCreate(lenght))
    {
        strcpy(this->cardName , cardName);
        this->cardName[lenght] = '\0';
    }
}
void Card::setAttack(int attack)
{
    if(attack > MAX_DAMAGE)
        this->attack = MAX_DAMAGE;
    else
        this->attack = attack ;
    recalculateEngergy();
}
void Card::setHealth(int health)
{
    if(health <=0 )
        this->health = 0;
    else if(health > MAX_HEALTH)
        this->health = MAX_HEALTH;
    else
        this->health = health;
    recalculateEngergy();
}
const char* Card::getCardName() const
{
    return this->cardName;
}
int Card::getAttack() const
{
    return this->attack;
}
int Card::getHealth() const
{
    return this->health;
}
double Card::getEnergy() const
{
    return this->energy;
}
///
/// other methods of class Card
///
void Card::recalculateEngergy()
{
    size_t temp = (this->health / 100.) + ( this->attack / 20.);

    if(temp > MAX_CARD_ENERGY)
        this->energy = MAX_CARD_ENERGY;
    else
        this->energy =  temp;
}
void Card::printCard() const
{
    cout << this->cardName  << endl;
    cout << this->attack    << endl;
    cout << this->health    << endl;
    cout << this->energy    << endl;

    printSkills();
}
void Card::printSkills() const
{
    for(size_t i = 0 ; i < countSkills ; i++)
    {
        cout << i << " : " ;
        skill[i]->printInfo();
    }
}
///
/// adding skills
///
void Card::addSkill(const Skill& other)
{
    if(countSkills < 3)
    {
        this->skill[countSkills++] = other.clone();
    }
}

///
/// saving loading
///

void Card::loadCardBinary(ifstream& input)
{
    size_t value;

    input.read((char*) &value , sizeof(size_t));
    // loading name length and the name
    char* tempName = new char[value+1];
    input.read((char*) tempName , value*sizeof(char));
    tempName[value] = '\0';
    setCardName(tempName);
    delete [] tempName;
    // loading the att and health
    input.read((char*) &value , sizeof(int));
    setAttack(value);
    input.read((char*) &value , sizeof(int));
    setHealth(value);

    char spellCode = '!';
    SpellFactory sF;

    do
    {
        input.read((char*) &spellCode , sizeof(char));

        if(spellCode == 'E')
            break;

        Skill* tempSkill = sF.giveMeSkill(spellCode);
        tempSkill->loadSpellBinary(input);

        addSkill(*tempSkill);

        delete tempSkill;

    }while(spellCode != 'E');
}

void Card::saveCardBinary(ofstream& output)
{
    size_t nameLenght = strlen(this->cardName);

    output.write((char*) &nameLenght , sizeof(size_t));
    output.write((char*) cardName , nameLenght* sizeof(char));
    output.write((char*) &attack , sizeof(int));
    output.write((char*) &health , sizeof(int));

    for(size_t i = 0 ; i < getCountSkills() ; i++)
    {
        skill[i]->saveSpellBinary(output);
    }

    char endOFCard = 'E';
    output.write((char*) &endOFCard , sizeof(char));
}

///
/// Attacking
///

int Card::cardAttack(Deck& mine , Deck& enemy , Deck& graveyard)
{
    cout << "'p' - pure attack 's' - spells" << endl;

    char code;
    do
    {
        cin.clear();
        cin.sync();


        cin >> code ;
    }while(code != 'p'  && code != 's');

    if(code == 's')
    {
        if(spellAttack(mine ,  enemy , graveyard))
            return 0; // if there aren't any spells we return to let the player use his card as PURE ATTACK
    }

    return pureAttack(enemy);
}

bool Card::spellAttack(Deck& mine , Deck& enemy , Deck& graveyard)
{
    if(getCountSkills() <= 0)
        return false;

    size_t No;
    this->printSkills();
    cout << " Select te spell you want to use " << endl;
    do
    {
        cin.clear();
        cin.sync();


        cin >> No ;
        if(No < 4 && No >= 0 && cin )
        {
            // in order to use some spell second time you need to unfreeze it
            // to lose one spell turn to unfreeze it
            if(skill[No]->getCanBeUsed())
            {
                skill[No]->use(mine , enemy , graveyard);
                return true;
            }
            else
            {
                skill[No]->unFreeze();
                return false;
            }
        }

    }while(!cin || No > getCountSkills());
    return true;
}
int Card::pureAttack(Deck& enemies)
{
    // letting the player to chose whitch card to attack
    if(enemies.getCountCards() <= 0)
        return getAttack()*1.5;
    enemies.printDeck();
    cout << "Select the Guard you wanna attack if there isn't Guard you may attack Assasins!" << endl;

    size_t No;
    bool haveGuard = isGuard(enemies);
    if(!haveGuard)
        cout << "There aren't any guards on the table attack what you want" << endl;

    // then check if there aren't any guard ,he can attack any card he wants
    Guard* g;
    do
    {
        cin.clear();
        cin.sync();

        cin >> No ;

        if(cin && No < enemies.getCountCards())
        {
            if(haveGuard)
            {// if there is guard we check if the select card is guard
                g = dynamic_cast<Guard*>(enemies[No]);
                if(g)
                    break;
            }
            else    // if there aren't any guards we let him attack the choosen one
                break;
        }
    }while(!cin || No >= enemies.getCountCards());
    int enemyHealth = enemies[No]->getHealth();
    int myAttack = getAttack();
    // setting the health of the attacked

    enemies[No]->setHealth(enemyHealth - myAttack);

    if(enemies[No]->getHealth() <= 0)
        enemies.deleteCard(enemies[No]->getCardName());

    if(haveGuard)
        return 0;
    else
        return myAttack*1.5;
}

bool Card::isGuard(Deck& deck)
{
    for(size_t i = 0 ; i < deck.getCountCards() ; i++)
    {
        const Guard* g = dynamic_cast<const Guard*>(deck[i]);
        if(g)
            return false;
    }
    return false;
}
