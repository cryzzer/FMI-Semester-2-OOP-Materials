//
// Created by User on 28.4.2021 г..
//

#ifndef HW3_PRAC_MONSTERCARD_HPP
#define HW3_PRAC_MONSTERCARD_HPP

#include "card.hpp"

///inheriting Card virtually
class MonsterCard : virtual public Card {
private:
    unsigned int attackPoints;
    unsigned int defencePoints;
public:
    MonsterCard(std::string name = "", std::string effect = "", unsigned int attackPoints = 0,
                unsigned int defencePoints = 0);
    unsigned int getAttackPoints() const;
    unsigned int getDefencePoints() const;
    void setAttackPoints(unsigned int newAttackPoints);
    void setDefencePoints(unsigned int newDefencePoints);
    void print() override ;
};

///overloading operators to read/write information about MonsterCard
std::istream& operator>>(std::istream& in,MonsterCard& monster);
std::ostream& operator<<(std::ostream& out,const MonsterCard& monster);


#endif //HW3_PRAC_MONSTERCARD_HPP
