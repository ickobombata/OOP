#include "Player.h"
Player::Player()
    :hp(1000) , energy(100)
{
}

Player::~Player()
{

}
void Player::reduceHP(int hp)
{
    setHp(this->hp - hp);
}
void Player::setHp(int hp)
{
    if(hp <= 0)
        this->hp = 0;
    else
        this->hp = hp;
}
void Player::setEnergy(int energy)
{
    if(energy < MAX_ENERGY)
        this->energy = energy;
    else
        this->energy = MAX_ENERGY;

    if(energy <= 0)
        this->energy = 0;
}
void Player::upEnergy(int energy)
{
    setEnergy(getEnergy() + energy);
}
int Player::yourTurnToPlay(Deck& ownTableCards , Deck& enemyTableCards , Deck& graveyard)
{
    if(wannaPlaceCard())
        placeCard(ownTableCards);

    if(ownTableCards.getCountCards() > 0)
    {
        cout << ownTableCards.getCountCards() << endl;

        Card* temp = chooseCardToUse(ownTableCards);

        return temp->cardAttack(ownTableCards , enemyTableCards , graveyard);
    }
    return 0;
}

Card* Player::chooseCardToUse(Deck& ownTableCards)
{
    ownTableCards.printDeck();

    cout << " select the card you wanna use " << endl;
    size_t No;

    do
    {
        cin.clear();
        cin.sync();


        cin >> No ;

    }while(!cin || No > ownTableCards.getCountCards());

    return ownTableCards[No];
}

bool Player::wannaPlaceCard()
{
    cout << "Wana place card on the board ? 'y' - yes , 'n' - n" << endl;
    char code;

    do
    {
        cin.clear();
        cin.sync();


        cin >> code ;
    }while(code != 'n'  && code !='y');

    if( code == 'y')
        return true;

    return false;
}
void Player::placeCard(Deck& ownDeck)
{
    printDeck();
    cout << "Select the card you wanna place on the board" << endl;

    size_t No;

    do
    {
        cin.clear();
        cin.sync();

        cin >> No ;

    }while(!cin || No >= getCountCards());

    if(getEnergy() > Deck::operator[](No)->getEnergy())
    {
        ownDeck.addCard(*Deck::operator[](No));

        deleteCard(Deck::operator[](No)->getCardName());
    }

}



bool Player::loadPlayerBinary()
{
    cout << "Loading : " ;
    const char* filePath = getTheFilePath();

    ifstream input(filePath , ios::in | ios::binary);
    if(!input)
    {
        cout << " File problems " << endl;
        return false;
    }

    size_t playerHp = 0;
    size_t playerEnergy = 0;

    input.read((char*) &playerHp , sizeof(size_t));
    input.read((char*) &playerEnergy , sizeof(size_t));

    setHp(playerHp);
    setEnergy(playerEnergy);

    Deck::loadDeckBinary(input);
}
void Player::savePlayerBinary()
{
    cout << "Saving : " ;
    const char* filePath = getTheFilePath();

    ofstream output(filePath , ios::out | ios::binary);
    if(!output)
    {
        cout << " File problems " << endl;
        return ;
    }
    size_t playerHp = getHp();
    size_t playerEnergy = getEnergy();

    output.write((char*) &playerHp , sizeof(size_t));
    output.write((char*) &playerEnergy , sizeof(size_t));

    Deck::saveDeckBinary(output);
}

const char* Player::getTheFilePath() const
{
    char *buffer = new char[150];
    cout << "Select the Path to the player file" << endl;

    cin.sync();
    cin.clear();

    cin.getline(buffer , 150);

    return buffer;
}
