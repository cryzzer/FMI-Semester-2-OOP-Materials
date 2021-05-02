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

#include "deck.hpp"
#include <iostream>

Deck::Deck(std::string deckName) : deckName(deckName) {
}

std::string Deck::getDeckName() const {
    return deckName;
}

void Deck::setDeckName(std::string newDeckName) {
    deckName = newDeckName;
}

unsigned int Deck::getMonsterDeckCount() const {
    return monsterDeck.size();
}

unsigned int Deck::getSpellDeckCount() const {
    return spellDeck.size();
}

unsigned int Deck::getPendulumDeckCount() const {
    return pendulumDeck.size();
}

///for the next 3 functions if the card already exists 3 times in the deck, the card cannot be added
void Deck::addNewMonster(const MonsterCard &monster) {
    if ((this->timesCardExists<MonsterCard>(monster, monsterDeck)) <= 2) {
        monsterDeck.push_back(monster);
    }
    else {
        std::cout << "Card already exists 3 times, cannot add it to the deck!\n";
    }
}

void Deck::addNewSpell(const MagicCard &spell) {
    if ((this->timesCardExists<MagicCard>(spell, spellDeck) <= 2)) {
        spellDeck.push_back(spell);
    }
    else {
        std::cout << "Card already exists 3 times, cannot add it to the deck!\n";
    }
}

void Deck::addNewPendulum(const PendulumCard &pendulum) {
    if ((this->timesCardExists<PendulumCard>(pendulum, pendulumDeck) <= 2)) {
        pendulumDeck.push_back(pendulum);
    }
    else {
        std::cout << "Card already exists 3 times, cannot add it to the deck!\n";
    }
}

///basic setters
void Deck::setMonsterCard(int index, const MonsterCard &monster) {
    assert(index >= 0 && index <= monsterDeck.size());
    monsterDeck[index] = monster;
}

void Deck::setMagicCard(int index, const MagicCard &spell) {
    assert(index >= 0 && index <= spellDeck.size());
    spellDeck[index] = spell;
}

void Deck::setPendulumCard(int index, const PendulumCard &pendulum) {
    assert(index >= 0 && index <= pendulumDeck.size());
    pendulumDeck[index] = pendulum;
}

///clearing the the 3 vectors that store the 3 types of cards
void Deck::eraseDeck() {
    monsterDeck.clear();
    spellDeck.clear();
    pendulumDeck.clear();
}


void Deck::printDeck() {
    std::cout << deckName << '|' << monsterDeck.size() << '|' << spellDeck.size() << '|' << pendulumDeck.size() << "\n";

    for (auto x: monsterDeck) {
        x.print();
    }
    std::cout << std::endl;
    for (auto x: spellDeck) {
        x.print();
    }
    std::cout << std::endl;
    for (auto x: pendulumDeck) {
        x.print();
    }
    std::cout << std::endl;
}

///using template because there are 3 variants of cards
template<class T>
int Deck::timesCardExists(const T &addingCard, std::vector<T> &searchDeck) {
    int timesExists = 0;
    for (const auto& x: searchDeck) {
        if (x.getName() == addingCard.getName()) {
            timesExists++;
        }
    }
    return timesExists;
}

///reading information from 'istream' with a certain format, and after that add this information to the deck
std::istream &operator>>(std::istream &in, Deck &deck) {
    std::string tempDeckName;
    std::string monsters;
    std::string spells;
    std::string pendulums;

    std::getline(in, tempDeckName, '|');
    std::getline(in, monsters, '|');
    std::getline(in, spells, '|');
    std::getline(in, pendulums, '\n');

    deck.setDeckName(tempDeckName);

    int monsterCount = std::stoi(monsters);
    int spellCount = std::stoi(spells);
    int pendulumCount = std::stoi(pendulums);

    for (int i = 0; i < monsterCount; i++) {
        MonsterCard tempMonster;
        in >> tempMonster;
        deck.addNewMonster(tempMonster);
    }
    for (int i = 0; i < spellCount; i++) {
        MagicCard tempSpell;
        in >> tempSpell;
        deck.addNewSpell(tempSpell);
    }
    for (int i = 0; i < pendulumCount; i++) {
        PendulumCard tempPendulum;
        in >> tempPendulum;
        deck.addNewPendulum(tempPendulum);
    }
    return in;
}

///read information form the deck, and write it to 'ostream' with a certain format
std::ostream &operator<<(std::ostream &out, const Deck &deck) {
    out << deck.getDeckName() << '|' << deck.getMonsterDeckCount() << '|' << deck.getSpellDeckCount() << '|'
        << deck.getPendulumDeckCount() << '\n';
    for (const auto &x : deck.monsterDeck) {
        out << x;
    }
    for (const auto &x : deck.spellDeck) {
        out << x;
    }
    for (const auto &x : deck.pendulumDeck) {
        out << x;
    }

    return out;
}


