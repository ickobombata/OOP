#pragma once

#include <iostream>
#include "header.h"
#include "Assasin.h"
#include "Guard.h"
#include "cardFactory.h"

/// change it in order to read skills from file and so on
///
class Deck
{
private:
    char* deckFilePath;
    unsigned int countCards;
    unsigned int maxCards;
    Card **c;
public:
    Deck(char* deckFilePath); // with file Path in order to save it there or load from there
    Deck(); // hint: to store local decks
    ~Deck();
    Deck& operator+= (const Card& other); // add card to the deck on the left
    Deck& operator+= (const Deck& other); // add deck to the deck on the left
    Deck& operator= (const Deck& other); // what's on right put it on the left
    const Deck operator+ (const Deck& other) const; // return the deck with added card
    const Deck operator+ (const Card& other) const; // return the deck with added deck
    bool operator== (const Deck& other) const; // if the two decks are equal TRUE ! else False
    bool operator!= (const Deck& other) const; // if the two decks are not equal TRUE
    bool operator> (const Deck& other) const; // Sum of attack and health and greater
    bool operator< (const Deck& other) const; // less
    bool operator<= (const Deck& other) const; //  less or equal
    bool operator>= (const Deck& other) const; // greater or equal to to the deck on the right
    const Card* operator[] (const int index) const; // give me the Pointer to the position INDEX
    Card* operator[] (const int index) ; // give me constant Pointer to the position Index
    Deck& operator-= (const Card& other); // deleting card from deck
    Deck& operator-= (const Deck& other); // deleting cards from deck
    Deck operator- (const Card& other); // allmost oposit of operator+
    Deck operator- (const Deck& other); // allmost oposit of operator+
public:
    void addCard(const Card& other);
    bool deleteCard(const char* cardName);
    void best5cards(char* chooseCriterion);
    void printDeck() const ;
    void loadDeck();
    bool loadDeckBinary(ifstream& input);
    void saveDeckBinary(ofstream& output);

    void setFilePath(const char* path) ;
    const char* getFilePath() const { return this->deckFilePath; }
    int getCountCards() const;
    int getMaxCards() const;
private:
    bool cardExists(const Deck & other  ,const char* cardName);
    bool validDeck();
    int smartFindPos(const char* cardName) const ;
    void shift(int pos);
    bool equalNames(const char* name1 ,const  char* name2) const ;
    char* nameFile() const;
    void enter5bestInFile(int arr[5] , int byWhat) const;
    void findBestCards(int*& arr , int byWhat);
    int getPower(const Deck& other) const; // power is the sum of attack and health in some way!
private:
    void unsafeDeleteFilePath();
    void unsafeDeleteCards();
    bool unsafeCreateFilePath(int length);
    bool unsafeCreateCards(int length);
    bool smartResizeDeck();
    bool resizeDeck();
};

const Deck operator+(const Card& c , const Deck& d); // takes Card and a Deck and allocates Deck with the card and deck
ostream& operator<< (ostream& out , const Deck& d); // streams the given Deck

