#include "BattleField.h"

BattleField::BattleField()
    :round(0)
{
    chooseMode();
    fight();
}

BattleField::~BattleField()
{

}


void BattleField::fight()
{
    while(p1.getHp() > 0 && p2.getHp() > 0)
    {
    cout << "PLAYER 1 TURN " << endl;
    cout << "P1 " << "HP: " << p1.getHp() << " Energy: " << p1.getEnergy() << endl
         << "P2 " << "HP: " << p2.getHp() << " Energy: " << p2.getEnergy() << endl ;
    cout << Player1.getCountCards() << endl;
    p2.reduceHP(p1.yourTurnToPlay(Player1 ,Player2 , Graveyard));

    if(p2.getHp() <= 0 )
        break;

    cout << "PLAYER 2 TURN " << endl;
    cout << "P1 " << "HP: " << p1.getHp() << " Energy: " << p1.getEnergy() << endl
         << "P2 " << "HP: " << p2.getHp() << " Energy: " << p2.getEnergy() << endl ;

    int hpReduction = p2.yourTurnToPlay(Player2 , Player1 , Graveyard);
    p1.reduceHP(hpReduction);

    round++;

    p1.upEnergy(20);
    p2.upEnergy(20);
    }

    if(p1.getHp() == 0)
    {
        cout << "PLAYER 2 WON !!!!!" << endl;
    }
    else
    {
        cout << "PLAYER 1 WON !!!!!" << endl;
    }
}

void BattleField::chooseMode()
{
    cout << "'n' - New game \n"
         << "'l' - load game" << endl;

    char mode ;
    cin >> mode;
    if(mode == 'l')
        modeLoadGame();
    else
        modeNewGame();
}
void BattleField::modeLoadGame()
{

    p1.loadPlayerBinary();

    p2.loadPlayerBinary();
}
void BattleField::modeNewGame()
{
    Deck choosingDeck("base.txt");
    choosingDeck.loadDeck();

    cout << "Choose your cards from the deck " << endl;

    for(size_t i = 0 ; i < MAX_CARDS ; i++)
    {
        playerPickCards(choosingDeck , p1 ,"Player 1 picks: ");
        playerPickCards(choosingDeck , p2 ,"Player 2 picks: ");
    }
}

void BattleField::playerPickCards(Deck& from ,Player& p , const char* prefix)
{
    from.printDeck();

    cout << prefix << endl;
    size_t tempCardChoise;
    do
    {
        cin.sync();
        cin.clear();
        cout << "Enter: " ;
        cin >> tempCardChoise;

    }while(!cin || tempCardChoise >= from.getCountCards());

    p.addCard(*from[tempCardChoise]);
    from.deleteCard(from[tempCardChoise]->getCardName());
}

/// getting
Deck& BattleField::getPlayer1TableDeck()
{
    return this->Player1;
}
Deck& BattleField::getPlayer2TableDeck()
{
    return this->Player2;
}
Deck& BattleField::getGraveyard()
{
    return this->Graveyard;
}
Player& BattleField::getPlayer1()
{
    return this->p1;
}
Player& BattleField::getPlayer2()
{
    return this->p2;
}
