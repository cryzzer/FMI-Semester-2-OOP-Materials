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

#include "card.hpp"

Card::Card(std::string name, std::string effect, unsigned int rarity) {
    assert(name.size() <= 50);///with assert checks if the numbers are in range
    assert(effect.size() <= 200);///with assert checks if the numbers are in range
    this->name = name;
    this->effect = effect;
    this->rarity = rarity;
}

Card::~Card() {
}


std::string Card::getName() const {
    return name;
}

std::string Card::getEffect() const {
    return effect;
}

void Card::setName(std::string newName) {
    assert(newName.size() <= 50);///with assert checks if the numbers are in range
    this->name = newName;
}

void Card::setEffect(std::string newEffect) {
    assert(newEffect.size() <= 200);///with assert checks if the numbers are in range
    effect = newEffect;
}

void Card::setRarity(unsigned int newRarity) {
    rarity = newRarity;
}

unsigned int Card::getRarity() const {
    return rarity;
}

///returning the ostream using doprint
std::ostream &operator<<(std::ostream &out, const Card &b) {
    return b.doprint(out);
}

bool Card::operator>(const Card &rhs) const {
    return this->rarity > rhs.rarity;
}

bool Card::operator<(const Card &rhs) const {
    return this->rarity < rhs.rarity;
}


