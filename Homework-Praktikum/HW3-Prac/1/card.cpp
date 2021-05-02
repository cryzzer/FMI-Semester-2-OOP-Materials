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

#include "card.hpp"

Card::Card(std::string name, std::string effect) {
    assert(name.size() <= 50);///with assert checks if the numbers are in range
    assert(effect.size() <= 200);///with assert checks if the numbers are in range
    this->name = name;
    this->effect = effect;
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

