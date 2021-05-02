//
// Created by User on 28.4.2021 г..
//

#ifndef HW3_PRAC_DECK_HPP
#define HW3_PRAC_DECK_HPP

#include "pendulumCard.hpp"
#include <vector>


class Deck {
private:
    std::string deckName;
    ///3 vectors to store the 3 types of cards
    std::vector<MonsterCard> monsterDeck;
    std::vector<MagicCard> spellDeck;
    std::vector<PendulumCard> pendulumDeck;

    ///function that checks how many times a card exists in the deck of this type
    template<class T>
    int timesCardExists(const T& addingCard, std::vector<T> &searchDeck);
public:
    Deck(std::string deckName = "");
    std::string getDeckName() const;
    void setDeckName(std::string newDeckName);

    unsigned int getMonsterDeckCount() const;
    unsigned int getSpellDeckCount() const;
    unsigned int getPendulumDeckCount() const;

    void addNewMonster(const MonsterCard& monster);
    void addNewSpell(const MagicCard& spell);
    void addNewPendulum(const PendulumCard& pendulum);

    void setMonsterCard(int index, const MonsterCard& monster);
    void setMagicCard(int index, const MagicCard& spell);
    void setPendulumCard(int index, const PendulumCard& pendulum);

    void eraseDeck();

    void printDeck();

    friend std::ostream& operator<<(std::ostream& out,const Deck& deck);
};
///overloading operators in order to use them to manipulate the deck
std::istream& operator>>(std::istream& in,Deck& deck);
std::ostream& operator<<(std::ostream& out,const Deck& deck);


#endif //HW3_PRAC_DECK_HPP
