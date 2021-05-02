//
// Created by User on 28.4.2021 г..
//

#include "monsterCard.hpp"
#include <iostream>

///calling the constructor Card into the initializing list
MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int attackPoints, unsigned int defencePoints)
        : Card(name, effect) {

    ///checking if the attackPoints and defencePoints are positive numbers
    assert(attackPoints >= 0);
    assert(defencePoints >= 0);
    this->attackPoints = attackPoints;
    this->defencePoints = defencePoints;
}

unsigned int MonsterCard::getAttackPoints() const {
    return attackPoints;
}

unsigned int MonsterCard::getDefencePoints() const {
    return defencePoints;
}

void MonsterCard::setAttackPoints(unsigned int newAttackPoints) {
    ///checking if the integer is positive number
    assert(newAttackPoints >= 0);
    attackPoints = newAttackPoints;
}

void MonsterCard::setDefencePoints(unsigned int newDefencePoints) {
    ///checking if the integer is positive number
    assert(newDefencePoints >= 0);
    defencePoints = newDefencePoints;
}

void MonsterCard::print() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Effect: " << getEffect() << std::endl;
    std::cout << "AttackPoints: " << attackPoints << std::endl;
    std::cout << "DefencePoints: " << defencePoints << std::endl;
}

std::istream& operator>>(std::istream& in,MonsterCard& monster){
    std::string tempName;
    std::string tempEffect;
    std::string tempAttack;
    std::string tempDefence;

    ///getting the string until we meet '|'
    std::getline(in,tempName,'|');
    std::getline(in,tempEffect,'|');
    std::getline(in,tempAttack,'|');
    std::getline(in,tempDefence, '\n');

    int tempAttackPoints = std::stoi(tempAttack);///converting the string into integer
    int tempDefencePoints = std::stoi(tempDefence);///converting the string into integer

    ///assigning the values into monster
    monster = MonsterCard(tempName,tempEffect,tempAttackPoints,tempDefencePoints);

    return in;
}

std::ostream& operator<<(std::ostream& out,const MonsterCard& monster){
    ///writing the information into certain format
    out << monster.getName() << '|' << monster.getEffect() << '|' << monster.getAttackPoints() << '|' << monster.getDefencePoints() << '\n';
    return out;
}