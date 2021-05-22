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
#include "pendulumCard.hpp"
#include <iostream>

///calling the constructors "Card,MonsterCard,MagicCard" into the initializing list
PendulumCard::PendulumCard(std::string name, std::string effect, unsigned int rarity, unsigned int attackPoints,
                           unsigned int defencePoints, CardType spellType, int pendulumScale)
        : MonsterCard(name, effect, rarity, attackPoints, defencePoints),
          MagicCard(name, effect, rarity, spellType),
          Card(name, effect, rarity) {
    assert(pendulumScale >= 1 && pendulumScale <= 13);///checking if the pendulumScale is in this range
    this->pendulumScale = pendulumScale;
}

int PendulumCard::getPendulumScale() const {
    return pendulumScale;
}

void PendulumCard::setPendulumScale(int newPendulumScale) {
    ///checking if the pendulumScale is in this range
    assert(newPendulumScale >= 1 && newPendulumScale <= 13);
    pendulumScale = newPendulumScale;
}

void PendulumCard::print() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Effect: " << getEffect() << std::endl;
    std::cout << "Rarity: " << getRarity() << std::endl;
    std::cout << "AttackPoints: " << getAttackPoints() << std::endl;
    std::cout << "DefencePoints: " << getDefencePoints() << std::endl;
    std::cout << "CardType: " << (int) getCardType() << std::endl;
    std::cout << "PendulumScale: " << pendulumScale << std::endl;
}

Card *PendulumCard::clone() {
    return new PendulumCard(*this);
}

std::istream &operator>>(std::istream &in, PendulumCard &pendulum) {
    std::string tempName;
    std::string tempEffect;
    std::string tempRare;
    std::string tempAttack;
    std::string tempDefence;
    std::string tempType;
    std::string tempPendulumScaleString;

    ///getting the string until we meet '|'
    std::getline(in, tempName, '|');
    std::getline(in, tempEffect, '|');
    std::getline(in, tempRare, '|');
    std::getline(in, tempAttack, '|');
    std::getline(in, tempDefence, '|');
    std::getline(in, tempType, '|');
    std::getline(in, tempPendulumScaleString, '\n');

    unsigned int tempRarity = std::stoul(tempRare);

    int tempAttackPoints = std::stoi(tempAttack);///converting the string into integer
    int tempDefencePoints = std::stoi(tempDefence);///converting the string into integer

    CardType tempCardType;
    defineCardType(tempType, tempCardType);///get the type of card

    int tempPendulumScale = std::stoi(tempPendulumScaleString);///converting the string into integer


    ///assigning the values into pendulum
    pendulum.setName(tempName);
    pendulum.setEffect(tempEffect);
    pendulum.setRarity(tempRarity);
    pendulum.setAttackPoints(tempAttackPoints);
    pendulum.setDefencePoints(tempDefencePoints);
    pendulum.setCardType(tempCardType);
    pendulum.setPendulumScale(tempPendulumScale);

    return in;
}

std::ostream &operator<<(std::ostream &out, const PendulumCard &pendulum) {
    ///writing the information into certain format
    out << pendulum.getName() << '|' << pendulum.getEffect() << '|' << pendulum.getRarity() << '|'
        << pendulum.getAttackPoints() << '|'
        << pendulum.getDefencePoints() << '|' << pendulum.getPendulumScale() << '|' << pendulum.getCardTypeString()
        << "\n";
    return out;
}
