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

#ifndef HW4_PRAC_DUELIST_HPP
#define HW4_PRAC_DUELIST_HPP

#include "deck.hpp"
#include <fstream>


class Duelist {
private:
    std::string playerName;
    Deck deck;
public:
    Duelist(std::string playerName = "", Deck deck = Deck());
    Deck& getDeck();
    std::string getPlayerName();
    void setDeck(const Deck& newDeck);
    bool saveDeck(const char* fileName);
    bool loadDeck(const char* fileName);

    void display();

    void duel(Duelist& rhs);
};

std::istream& operator>>(std::istream& in, Duelist& duelist);
std::ostream& operator<<(std::ostream& out, Duelist& duelist);


#endif //HW4_PRAC_DUELIST_HPP
