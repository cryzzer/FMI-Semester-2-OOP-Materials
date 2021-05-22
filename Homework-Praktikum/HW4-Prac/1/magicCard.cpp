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

#include "magicCard.hpp"
#include <iostream>

///calling the constructor Card into the initializing list
MagicCard::MagicCard(std::string name, std::string effect, unsigned int rarity, CardType cardType)
        : Card(name, effect, rarity), spellType(cardType) {
}


CardType MagicCard::getCardType() const {
    return spellType;
}


void MagicCard::setCardType(CardType newCardType) {
    spellType = newCardType;
}

void MagicCard::print() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Effect: " << getEffect() << std::endl;
    std::cout << "Rarity: " << getRarity() << std::endl;
    std::cout << "CardType: " << (int) spellType << std::endl;
}

std::string MagicCard::getCardTypeString() const {
    std::string cardTypeString;
    switch (getCardType()) {
        case CardType::SPELL:
            cardTypeString = "SPELL";
            break;
        case CardType::TRAP:
            cardTypeString = "TRAP";
            break;
        case CardType::BUFF:
            cardTypeString = "BUFF";
            break;
    }
    return cardTypeString;
}

void defineCardType(std::string &typeString, CardType &cardType) {
    if (typeString == "BUFF") {
        cardType = CardType::BUFF;
    } else if (typeString == "TRAP") {
        cardType = CardType::TRAP;
    } else {
        cardType = CardType::SPELL;
    }
}

std::istream &operator>>(std::istream &in, MagicCard &spell) {
    std::string tempName;
    std::string tempEffect;
    std::string tempRare;
    std::string tempType;

    ///getting the string until we meet '|'
    std::getline(in, tempName, '|');
    std::getline(in, tempEffect, '|');
    std::getline(in, tempRare, '|');
    std::getline(in, tempType, '\n');

    unsigned int tempRarity = std::stoul(tempRare);

    CardType tempCardType;
    defineCardType(tempType, tempCardType);///get the type of card

    spell = MagicCard(tempName, tempEffect, tempRarity, tempCardType);///assigning the values into spell

    return in;
}

std::ostream &operator<<(std::ostream &out, const MagicCard &spell) {
    ///writing the information into certain format
    out << spell.getName() << '|' << spell.getEffect() << '|' << spell.getRarity() << '|' << spell.getCardTypeString()
        << '\n';
    return out;
}