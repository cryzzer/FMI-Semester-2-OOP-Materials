
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

#ifndef HW4_PRAC_DECK_HPP
#define HW4_PRAC_DECK_HPP

#include "pendulumCard.hpp"
#include <vector>

class Deck {
private:
    std::string deckName;
    std::vector<Card*> deck;


public:
    Deck(std::string deckName = "");
    Deck(const Deck& rhs);
    Deck& operator=(const Deck& rhs);
    ~Deck() = default;

    std::string getDeckName() const;
    void setDeckName(std::string newDeckName);


    unsigned int getMonsterCount() const;
    unsigned int getSpellCount() const;
    unsigned int getPendulumCount() const;
    unsigned int getCardCount() const;

    void addCard(Card* card);
    bool bothTypesAreEqual(unsigned int index, Card* card);
    void setCard(unsigned int index, Card* card);

    void eraseDeck();
    void printDeck();
    void shuffle();
    void setDeckInOrder();

};


#endif //HW4_PRAC_DECK_HPP