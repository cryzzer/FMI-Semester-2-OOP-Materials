//
// Created by User on 22.5.2021 г..
//

#include "deck.hpp"
#include <iostream>

#include <stdlib.h>
#include <time.h>

Deck::Deck(std::string deckName) : deckName(deckName) {
}

Deck::Deck(const Deck &rhs) {
    this->deckName = rhs.deckName;
    for(auto cards : rhs.deck){
        deck.push_back(cards->clone());
    }
}

Deck & Deck::operator=(const Deck &rhs) {
    if(this != &rhs){
        eraseDeck();

        this->deckName = rhs.deckName;
        for(auto cards : rhs.deck){
            deck.push_back(cards->clone());
        }
    }
    return *this;
}

Deck::~Deck() {
    eraseDeck();
}

std::string Deck::getDeckName() const {
    return deckName;
}

void Deck::setDeckName(std::string newDeckName) {
    deckName = newDeckName;
}

Card * Deck::getCard(size_t index) {
    assert(index < deck.size());

    return deck[index];
}

int Deck::timesCardExists(Card *card) {
    int timesExists = 0;
    for (size_t i = 0; i < deck.size(); i++) {
        if (deck[i]->getName() == card->getName() && bothTypesAreEqual(i,card)) {
            timesExists++;
        }
    }
    return timesExists;
}

void Deck::addCard(Card *card) {
    if(timesCardExists(card) <= 2){
        deck.push_back(card);
    }
    else{
        delete card;
    }
}

bool Deck::bothTypesAreEqual(unsigned int index, Card *card) {
    assert(index < deck.size());

    auto monPtr = dynamic_cast<MonsterCard*>(card);
    auto spellPtr = dynamic_cast<MagicCard*>(card);
    auto pendPtr = dynamic_cast<PendulumCard*>(card);

    if(monPtr && pendPtr == nullptr){
        auto otherPtr = dynamic_cast<MonsterCard*>(deck[index]);
        auto excludePtr = dynamic_cast<PendulumCard*>(deck[index]);
        if(otherPtr && excludePtr == nullptr){
            return true;
        }
    }
    else if(spellPtr && pendPtr == nullptr){
        auto otherPtr = dynamic_cast<MagicCard*>(deck[index]);
        auto excludePtr = dynamic_cast<PendulumCard*>(deck[index]);
        if(otherPtr && excludePtr == nullptr){
            return true;
        }
    }
    else if(pendPtr){
        auto otherPtr = dynamic_cast<PendulumCard*>(deck[index]);
        if(otherPtr){
            return true;
        }
    }
    return false;
}



void Deck::setCard(unsigned int index, Card *card) {
    if(bothTypesAreEqual(index, card)){
        delete deck[index];
        deck[index] = card;
    }
    else{
        std::cout << "===========These two types does not match!================\n";
    }
}


unsigned int Deck::monsterCount() const {
    int counter = 0;

    for(auto card: deck){
        auto monsterPtr = dynamic_cast<MonsterCard*>(card);
        auto pendPtr = dynamic_cast<PendulumCard*>(card);
        if(monsterPtr && pendPtr == nullptr){
            counter++;
        }
    }
    return counter;
}

unsigned int Deck::spellCount() const {
    int counter = 0;

    for(auto card: deck){
        auto spellPtr = dynamic_cast<MagicCard*>(card);
        auto pendPtr = dynamic_cast<PendulumCard*>(card);
        if(spellPtr && pendPtr == nullptr){
            counter++;
        }
    }
    return counter;
}

unsigned int Deck::pendulumCount() const {
    int counter = 0;

    for(auto card: deck){
        auto pendPtr = dynamic_cast<PendulumCard*>(card);
        if(pendPtr){
            counter++;
        }
    }
    return counter;
}

unsigned int Deck::cardCount() const {
    return deck.size();
}

void Deck::eraseDeck() {
    for(auto card : deck){
        delete card;
    }
    deck.clear();
}

void Deck::printDeck() {
    for(auto card : deck){
        card->print();
        std::cout << std::endl;
    }
}

void Deck::shuffle() {
    srand (time(NULL));

    std::vector<Card*> temp;
    int* takenPositions = new int[deck.size()];
    for(int i = 0; i < deck.size(); i++){
        takenPositions[i] = -1;
    }

    for(int i = 0; i < deck.size(); i++){
        int randomNum = rand() % deck.size();
        bool existingNumber = false;

        for(int j = 0; j < i; j++){
            if(randomNum == takenPositions[j]){
                existingNumber = true;
                break;
            }
        }

        if(existingNumber){
            i--;
            continue;
        }
        else{
            temp.push_back(deck[randomNum]);
            takenPositions[i] = randomNum;
        }
    }
    delete[] takenPositions;
    deck = temp;
}

void Deck::setDeckInOrder() {
    std::vector<Card*> temp;

    unsigned int counter = monsterCount();

    for(auto card : deck){
        if(counter != 0){
            auto monsterPtr = dynamic_cast<MonsterCard*>(card);
            auto pendPtr = dynamic_cast<PendulumCard*>(card);
            if(monsterPtr && pendPtr == nullptr){
                temp.push_back(card);
                counter--;
            }
        }
        else{
            break;
        }
    }

    counter = spellCount();

    for(auto card : deck){
        if(counter != 0){
            auto spellPtr = dynamic_cast<MagicCard*>(card);
            auto pendPtr = dynamic_cast<PendulumCard*>(card);
            if(spellPtr && pendPtr == nullptr){
                temp.push_back(card);
                counter--;
            }
        }
        else{
            break;
        }
    }

    counter = pendulumCount();

    for(auto card : deck){
        if(counter != 0){
            auto pendPtr = dynamic_cast<PendulumCard*>(card);
            if(pendPtr){
                temp.push_back(card);
                counter--;
            }
        }
        else{
            break;
        }
    }
    deck = temp;
}

///reading information from 'istream' with a certain format, and after that add this information to the deck
std::istream &operator>>(std::istream &in, Deck &deck) {
    std::string tempDeckName;
    std::string tempCardsCount;
    std::string monsters;
    std::string spells;
    std::string pendulums;

    std::getline(in, tempDeckName, '|');
    std::getline(in, tempCardsCount, '|');
    std::getline(in, monsters, '|');
    std::getline(in, spells, '|');
    std::getline(in, pendulums, '\n');

    deck.setDeckName(tempDeckName);

    int cardsCount = std::stoi(tempCardsCount);
    int monsterCount = std::stoi(monsters);
    int spellCount = std::stoi(spells);
    int pendulumCount = std::stoi(pendulums);

    for (int i = 0; i < monsterCount; i++) {
        MonsterCard tempMonster;
        in >> tempMonster;
        deck.addCard(new MonsterCard(tempMonster));
    }
    for (int i = 0; i < spellCount; i++) {
        MagicCard tempSpell;
        in >> tempSpell;
        deck.addCard(new MagicCard(tempSpell));
    }
    for (int i = 0; i < pendulumCount; i++) {
        PendulumCard tempPendulum;
        in >> tempPendulum;
        deck.addCard(new PendulumCard(tempPendulum));
    }
    return in;
}

///read information form the deck, and write it to 'ostream' with a certain format
std::ostream &operator<<(std::ostream &out, Deck &deck) {
    out << deck.getDeckName() << '|' << deck.cardCount() << '|' << deck.monsterCount() << '|' << deck.spellCount() << '|'
        << deck.pendulumCount() << '\n';

    for(auto x : deck.deck){
        out << *x;
    }
    return out;
}


