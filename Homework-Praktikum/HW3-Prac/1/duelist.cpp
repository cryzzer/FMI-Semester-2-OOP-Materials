/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 1
* @compiler GCC
*/

#include "duelist.hpp"
#include <iostream>

Duelist::Duelist(std::string playerName, Deck deck) : playerName(playerName), deck(deck) {
}

Deck& Duelist::getDeck(){
    return deck;
}

void Duelist::setDeck(const Deck &newDeck) {
    deck = newDeck;
}

bool Duelist::loadDeck(const char *fileName) {
    ///append the file, that means that we open the file without changing any information
    std::ifstream loadingDeck (fileName, std::ios::app);

    ///if we cannot open the file correctly we return false because the action was unsuccessful
    if(!loadingDeck.is_open()){
        return false;
    }

    ///erasing the deck
    getDeck().eraseDeck();

    ///entering new cards from file via operator>> into the deck
    loadingDeck >> *this;

    loadingDeck.close();

    return true;
}

bool Duelist::saveDeck(const char *fileName) {
    ///when opening the file by default we trunc it
    std::ofstream savingDeck(fileName);

    ///if we cannot open the file correctly we return false because the action was unsuccessful
    if(!savingDeck.is_open()){
        return false;
    }

    ///writing the information form deck into the file via operator<<
    savingDeck << *this;

    savingDeck.close();

    return true;
}

void Duelist::display() {
    ///printing the information from deck using operator<<
    std::cout << *this << std::endl;
}

///calling the operators from Deck::
std::istream& operator>>(std::istream& in,Duelist& duelist){
    in >> duelist.getDeck();
    return in;
}
std::ostream& operator<<(std::ostream& out,Duelist& duelist){
    out << duelist.getDeck();
    return out;
}