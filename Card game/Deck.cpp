#include "Deck.h"

Deck::Deck(char* deckFilePath) : countCards(0) , maxCards(1)
{
    if(unsafeCreateFilePath(strlen(deckFilePath)+1))
       strcpy(this->deckFilePath , deckFilePath);
    unsafeCreateCards(this->maxCards);
    //loadDeck();
}
Deck::Deck() : countCards(0) , maxCards(1)
{
    if(unsafeCreateFilePath(2))
        strcpy(this->deckFilePath , "-");
    unsafeCreateCards(this->maxCards);
    //loadDeck();
}
Deck::~Deck()
{
    unsafeDeleteCards();
    unsafeDeleteFilePath();
}
Deck& Deck::operator+=(const Card& other)
{
    // using the addCard f-on less coding
    addCard(other);
    return *this;
}
Deck& Deck::operator+= (const Deck& other)
{
    // using the Deck+= Card method for every card in Deck 2
    for(int i = 0 ; i < other.countCards ; i++)
        (*this) += *(other.c[i]);
    return (*this);
}
const Deck Deck::operator+ (const Deck& other) const
{
    // also using +=
    Deck temp;
    temp += other;
    temp += (*this);
    return temp;
}
const Deck Deck::operator+(const Card & other) const
{
    Deck temp;
    temp += (*this);
    temp += other;
    return temp;
}
const Deck operator+(const Card& c , const Deck & d)
{
    Deck temp;
    temp += c;
    temp += d;
    return temp;
}
Deck& Deck::operator= (const Deck& other)
{
    // deleting the cards from deck 1 because we dont need them
    // then seting the number of Cards = to the deck 2 num. cards
    // allocating memory for Deck 1 with and copying from deck 2
    // to deck 1 and returing deck 1
    if(this != &other)
    {
        unsafeDeleteCards();
        this->maxCards = other.maxCards;
        this->countCards = other.countCards;
        unsafeCreateCards(other.maxCards);
        for(int i = 0; i < other.countCards ; i++)
            {
                this->c[i] = other.c[i];
            }
    }
    return (*this);
}
bool Deck::operator== (const Deck& other) const
{
    // testing if the cards are equal
    if(this->countCards != other.countCards)
        return 0;
    for(int i = 0 ; i < this->countCards ; i++)
        if(this->c[i] != other.c[i])
            return 0;
    return 1;
}
bool Deck::operator!=(const Deck& other) const
{
    // testing if the cards are not equal
    // using the == method
    return !(*this == other);
}
bool Deck::operator> (const Deck& other) const
{
    // getPower takes deck and sums the attack and health
    // and tests if the first is greater then the second
    int sum1 = getPower(*this) ;
    int sum2 = getPower(other) ;
    if(sum1 > sum2)
        return 1;
    return 0;
}
bool Deck::operator< (const Deck& other) const
{
    // getPower takes deck and sums the attack and health
    // and tests if the second is greater then the first
    int sum1 = getPower(*this) ;
    int sum2 = getPower(other) ;
    if(sum1 < sum2)
        return 1 ;
    return 0;
}
bool Deck::operator<= (const Deck& other) const
{
    // using operator> nicely done
    return !(*this > other);
}
bool Deck::operator>= (const Deck& other) const
{
    // operator< helps to calculate if the Deck1 >= Deck2
    return !(*this < other);
}
const Card* Deck::operator[] (const int index) const
{
    // if the index is posible to be allocated in the deck we return that pointer
    if(index > this->countCards)
        cout << "index out of range" << endl;
    return this->c[index];
}
Card* Deck::operator[] (const int index)
{
    // the same as above only this time we return const Pointer
    if(index > this->countCards)
        cout << "index out of range" << endl;
    return this->c[index];
}
ostream& operator<< (ostream& out , const Deck& d)
{
    // for every card in Deck d we stream the name
    // attack ,health and the energy of the card
    for(int i = 0 ; i < d.getCountCards() ; i++)
    {
        out << (*d[i]);
    }
    return out;
}
Deck& Deck::operator-= (const Card& other)
{
    // deletgin given card using the delteCArd method
    deleteCard(other.getCardName());
    return (*this);
}
Deck& Deck::operator-= (const Deck& other)
{
    // for every card in deck 2 we try and if posible delete it
    for(int i = 0 ; i < other.countCards ;i++)
        deleteCard(other.c[i]->getCardName());
    return (*this);
}
Deck Deck::operator- (const Card& other)
{
    // returns the deck with Cards of Deck 1 -= the given card
    Deck temp;
    temp = (*this);
    temp -= other;
    return temp;
}
Deck Deck::operator- (const Deck& other)
{
    // returns the deck with Cards of Deck 1 -= the cards in Deck2
    Deck temp;
    temp = (*this);
    temp -= other;
    return temp;
}
void Deck::addCard(const Card& other)
{
    // first check if the card allready exists
    // if needed resize the deck and after the last
    // card add the new one and increese the countCards

    if(!cardExists((*this) , other.getCardName()))
        return;
    smartResizeDeck();

    c[this->countCards++] = other.clone();
}

bool Deck::deleteCard(const char* cardName)
{
    // find the position of the wanted card
    // and after that shifting to left
    // if needed the deck will be resized in order to avoid
    // having 1 card in deck with 10000 slots

    int pos = smartFindPos(cardName);
    if(pos < 0)
    {
        cout << "Card : " << cardName <<  " not found" << endl;
        return false;
    }
    shift(pos);

    if(this->countCards + 5 < this->maxCards)
    {
        this->maxCards = this->maxCards - 5 ;

        resizeDeck();
    }
    return true;

}
void Deck::printDeck() const
{
    //printing deck
    for(size_t i = 0 ; i < this->countCards ;i++)
    {
        cout << "No " << i << endl;
        this->c[i]->printCard();
        cout << endl;
    }
}
///
/// SAVNG and LOADING decks
///
void Deck::loadDeck()
{
    // opeingn the file to read
    ifstream inFile(this->deckFilePath , ios::in);
    // countnig the cards by they're names
    if(inFile)
    {
        char cardCode = '!';
        cardFactory cF;

        while(cardCode != 'F')
        {
            inFile >> cardCode;
            if(!inFile)
            {
                cout << "File Problem" << endl;
                return;
            }
            if(cardCode == 'F')
                break;

            Card* tempCard = cF.giveMeCard(cardCode);
            tempCard->loadCard(inFile);
            addCard(*tempCard);
            delete tempCard;
        }
    }
    inFile.close();
}

bool Deck::loadDeckBinary(ifstream& input)
{
    char cardCode = '!';
    cardFactory cF;

    do
    {

        input.read((char*) &cardCode , sizeof(char));
        if(cardCode == 'F')
            break;

        Card* tempCard = cF.giveMeCard(cardCode);
        tempCard->loadCardBinary(input);
        addCard(*tempCard);
        delete tempCard;

    }while(cardCode != 'F');
}

void Deck::saveDeckBinary(ofstream& output)
{
    for(size_t i = 0 ; i < getCountCards() ; i++)
    {
        c[i]->saveCardBinary(output);
    }
    char endOfDeck = 'F';
    output.write((char*) &endOfDeck , sizeof(char));
}
void Deck::best5cards(char* chooseCriterion)
{
    if(this->countCards < 5)
        return;
    int *positionBuffer = new(nothrow) int[5] ;
    if(!positionBuffer)
    {
        cout << "Problem occured : No memory" << endl;
        return;
    }
    if(equalNames(chooseCriterion , "attack"))
    {
        findBestCards(positionBuffer , 1) ;
        enter5bestInFile(positionBuffer , 1);
    }
    else if (equalNames(chooseCriterion , "health"))
    {
        findBestCards(positionBuffer , 2) ;
        enter5bestInFile(positionBuffer , 2);
    }
    else if (equalNames(chooseCriterion , "energy"))
    {
        findBestCards(positionBuffer , 3) ;
        enter5bestInFile(positionBuffer , 3);
    }
    else
    {
        return;
    }
    delete []positionBuffer;
}
void Deck::findBestCards(int*& arr , int byWhat)
{
    int counter = 0 ;
    int maxPosAt = 0;
    int maxIs = 0;
    while(counter < 5)
        {
            maxIs = 0 ;
            maxPosAt = 0;
            for(int i = 0 ; i < this->countCards ; i++)
            {
                int currentCardAtribute = 0;
                switch(byWhat)
                {
                    case 1: currentCardAtribute = this->c[i]->getAttack();
                            break;
                    case 2: currentCardAtribute = this->c[i]->getHealth();
                            break;
                    case 3: currentCardAtribute = this->c[i]->getEnergy();
                            break;
                }
                if( currentCardAtribute > maxIs && arr[0] != i
                    && arr[1] != i && arr[2] != i
                    && arr[3] != i )
                {
                    maxIs = currentCardAtribute;
                    maxPosAt = i;
                }
            }
            arr[counter] = maxPosAt;
            counter++;
        }
}
void Deck::enter5bestInFile(int arr[5] , int byWhat) const
{
    char buffer[100];
    strcpy(buffer , nameFile());
    switch(byWhat)
    {
        case 1: strcat(buffer , " byAttack");
                break;
        case 2: strcat(buffer , " byHealth");
                break;
        case 3: strcat(buffer , " byEnergy");
                break;
        default: return;
    }
    strcat(buffer , ".txt");
    ofstream outFile(buffer , ios::out);
    if(!outFile)
    {
        cout << " No memory : file cannot be created" << endl;
        return;
    }
    for(int i = 0 ; i < 5 ; i++)
        outFile << this->c[arr[i]]->getCardName() << " "
                << this->c[arr[i]]->getAttack() << " "
                << this->c[arr[i]]->getHealth() << " "
                << this->c[arr[i]]->getEnergy() << endl;

}
bool Deck::validDeck()
{
    // in order to know if the deck is valid
    // or maybe not we need to chekck it !
    if(this->countCards >= 5)
        return true;
    return false;
}
void Deck::unsafeDeleteFilePath()
{
    // deleting the array of chars if necessary
    if(!this->deckFilePath)
        delete []this->deckFilePath;
}
void Deck::unsafeDeleteCards()
{
    // deleting the array of cards if necessary
    for(size_t i = 0 ; i < this->countCards ; i++)
        delete c[i];

    delete [] this->c;
}
bool Deck::unsafeCreateFilePath(int length)
{
    // file path has it's length and knowing that
    // we make the new array of chars with length of path
        this->deckFilePath = new(nothrow) char[length];
    if(!this->deckFilePath)
        {
            cout << "Problem occured: Out of Memory" << endl;
            return 0;
        }
    return 1;
}
bool Deck::unsafeCreateCards(int length)
{
    // creating the knowing in the class array of cards
    this->c = new(nothrow) Card*[length];
    if(!this->c)
    {
         cout << "Problem occured: Out of Memory" << endl;
         return false;
    }
    return true;
}
bool Deck::smartResizeDeck()
{
    // smartResize makes some smart moves he tests if there is really need
    // to be called resize
    if(this->countCards +5 > this->maxCards && this->countCards != this->maxCards)
        return 1;
    if(this->countCards == this->maxCards)
        this->maxCards += 5 ;
    if(this->countCards + 5 < this->maxCards )
        this->maxCards -=5 ;

    resizeDeck();

    return 1;
}
bool Deck::resizeDeck()
{
    // we create new Card array with the new sizes and
    // copy everything and then redirect the pointer
    Card **temp = new(nothrow) Card*[this->maxCards];
    if(!temp)
    {
        cout << "Problem occured : out of Memory" << endl;
        return 0;
    }
    // changing the pointers to the temp
    for(size_t i = 0 ; i < this->countCards ; i++)
        temp[i] = this->c[i];

    delete [] c;
    this->c = temp;
    return 1;
}
bool Deck::equalNames(const char* name1 ,const char* name2) const
{
    // testing if two chars*s are equal
    if(strlen(name1) != strlen(name2))
        return false;
    for(int i = 0 ; i < strlen(name1) ; i++)
    {
        if(name1[i] != name2[i])
            return false;
    }
    return true;
}
int Deck::smartFindPos(const char* cardName) const
{
    //finding the position of a given card
    for(int i = 0 ; i < this->countCards ; i++)
    {
        char buffer[strlen(this->c[i]->getCardName())+1];
        strcpy(buffer , this->c[i]->getCardName());
        // equalNames is method to see if 2 char*s are equal
        if(equalNames(buffer , cardName))
            return i;
    }
    return -1;
}
void Deck::shift(int pos)
{
    // this is simple shifting to left
    delete this->c[pos];

    for(int i = pos ; i < this->countCards - 1; i++)
    {
        this->c[i] = this->c[i+1];
    }
    this->countCards--;
}
char* Deck::nameFile() const
{
    // the use of this method is to find the name
    // of the binary file throw his path
    // and after that i use it to make new text File
    // with the name of the binary file plus
    //  "Best5"
    int lastDot = 0;
    int lastBracket = 0;
    for(int i = 0 ; i < strlen(this->deckFilePath) ; i++)
    {
        if(this->deckFilePath[i] == '.')
            lastDot = i;
        if(this->deckFilePath[i] == '\\')
            lastBracket = i ;
    }
    int countTempPos = 0;
    char temp[lastDot - lastBracket + 1] ;
    for(int i = lastBracket ; i < lastDot ;i++)
        temp[countTempPos++] = this->deckFilePath[i];
    temp[lastDot] = '\0' ;
    strcat(temp , " Best5");

    return temp;
}
bool Deck::cardExists( const Deck & other , const char* cardName)
{
    for(int i = 0; i < other.countCards ; i++)
    {
        if(strcmp(other.c[i]->getCardName()  , cardName) == 0 )
        {
            cout << "This card : " << cardName << " allready exists! " << endl;
            return false;
        }
    }
    return true;
}
int Deck::getPower(const Deck& other) const
{
    int sum = 0 ;
    for(int i = 0 ; i < other.countCards ; i++)
    {
        sum += other.c[i]->getAttack() ;
        sum += other.c[i]->getHealth() ;
    }
    return sum;
}
int Deck::getCountCards() const
{
    return this->countCards;
}
int Deck::getMaxCards() const
{
    return this->maxCards;
}
void Deck::setFilePath(const char* path)
{
    delete [] this->deckFilePath;
    this->deckFilePath = new char[strlen(path) + 1];
    if(!this->deckFilePath)
        cout <<"No memory " << endl;

    strcpy(deckFilePath , path);

}

