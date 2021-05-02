//
// Created by User on 28.4.2021 г..
//

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

public:
    MagicCard(std::string name = "", std::string effect = "", CardType cardType = CardType::SPELL);
    CardType getCardType() const;
    void setCardType(CardType newCardType);
    void print() override;
    std::string getCardTypeString() const;///converting the CardType to string

};

void defineCardType(std::string& typeString, CardType& cardType);///converting the string into CardType

///overloading operators to read/write information about MagicCard
std::istream& operator>>(std::istream& in,MagicCard& spell);
std::ostream& operator<<(std::ostream& out,const MagicCard& spell);

#endif //HW3_PRAC_MAGICCARD_HPP
