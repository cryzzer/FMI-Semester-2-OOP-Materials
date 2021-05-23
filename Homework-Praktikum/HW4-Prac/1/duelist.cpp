/**
* Solution to homework assignment 4
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

Deck &Duelist::getDeck() {
    return deck;
}

std::string Duelist::getPlayerName() {
    return playerName;
}

void Duelist::setDeck(const Deck &newDeck) {
    deck = newDeck;
}

bool Duelist::loadDeck(const char *fileName) {
    ///append the file, that means that we open the file without changing any information
    std::ifstream loadingDeck(fileName, std::ios::app);

    ///if we cannot open the file correctly we return false because the action was unsuccessful
    if (!loadingDeck.is_open()) {
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
    if (!savingDeck.is_open()) {
        return false;
    }

    getDeck().setDeckInOrder();

    ///writing the information form deck into the file via operator<<
    savingDeck << *this;

    savingDeck.close();

    return true;
}

void Duelist::display() {
    ///printing the information from deck using operator<<
    std::cout << *this << std::endl;
}

void Duelist::duel(Duelist &rhs) {
    if (this->getDeck().cardCount() != rhs.getDeck().cardCount()) {
        std::cout << this->playerName << " has " << this->getDeck().cardCount() << " cards in the deck\n";
        std::cout << rhs.getPlayerName() << " has " << rhs.getDeck().cardCount() << " cards in the deck\n";
        std::cout << "\nBoth duelists must have equal number of cards in their decks if they want to duel each other!";
        return;
    }

    this->getDeck().shuffle();
    rhs.getDeck().shuffle();
    rhs.getDeck().shuffle();

    unsigned int player1Points = 0;
    unsigned int player2Points = 0;

    for (size_t i = 0; i < this->getDeck().cardCount(); i++) {
        std::cout << "======================================================================\n";
        std::cout << "ROUND " << i + 1 << std::endl;

        std::cout << *this->getDeck().getCard(i);
        std::cout << "VS\n";
        std::cout << *rhs.getDeck().getCard(i) << std::endl;
        if (*this->getDeck().getCard(i) > *rhs.getDeck().getCard(i)) {
            std::cout << this->getDeck().getCard(i)->getRarity() << " > " << rhs.getDeck().getCard(i)->getRarity()
                      << std::endl;
            player1Points++;
        } else if (*this->getDeck().getCard(i) < *rhs.getDeck().getCard(i)) {
            std::cout << this->getDeck().getCard(i)->getRarity() << " < " << rhs.getDeck().getCard(i)->getRarity()
                      << std::endl;
            player2Points++;
        } else {
            std::cout << this->getDeck().getCard(i)->getRarity() << " = " << rhs.getDeck().getCard(i)->getRarity()
                      << std::endl;
        }
        std::cout << "\n\n" << this->getPlayerName() << " : " << player1Points << "       " << rhs.getPlayerName()
                  << " : " << player2Points << "\n\n";
    }

    if (player1Points > player2Points) {
        std::cout << "THE WINNER IS: " << this->getPlayerName() << "  with " << player1Points << " points!\n";
    } else if (player1Points < player2Points) {
        std::cout << "THE WINNER IS: " << rhs.getPlayerName() << "  with " << player2Points << " points!\n";
    } else {
        std::cout << "IT'S A TIE, both players with " << player1Points << " points!\n";
    }
}

///calling the operators from Deck::
std::istream &operator>>(std::istream &in, Duelist &duelist) {
    in >> duelist.getDeck();
    return in;
}

std::ostream &operator<<(std::ostream &out, Duelist &duelist) {
    out << duelist.getDeck();
    return out;
}