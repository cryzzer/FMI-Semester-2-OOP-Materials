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

#ifndef HW3_PRAC_MAGICCARD_HPP
#define HW3_PRAC_MAGICCARD_HPP

#include "card.hpp"

///three different types of a card
enum class CardType{
    TRAP,
    BUFF,
    SPELL
};

///inheriting Card virtually
class MagicCard : virtual public Card {
private:
    CardType spellType;

    std::ostream& doprint(std::ostream& out) const override;
public:
    MagicCard(std::string name = "", std::string effect = "",unsigned int rarity = 0, CardType cardType = CardType::SPELL);
    CardType getCardType() const;
    void setCardType(CardType newCardType);
    void print() override;
    std::string getCardTypeString() const;///converting the CardType to string

    Card* clone() override;

};

void defineCardType(std::string& typeString, CardType& cardType);///converting the string into CardType

///overloading operators to read/write information about MagicCard
std::istream& operator>>(std::istream& in,MagicCard& spell);
std::ostream& operator<<(std::ostream& out,const MagicCard& spell);

#endif //HW3_PRAC_MAGICCARD_HPP
