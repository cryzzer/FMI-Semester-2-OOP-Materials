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

#ifndef HW3_PRAC_MONSTERCARD_HPP
#define HW3_PRAC_MONSTERCARD_HPP

#include "card.hpp"

///inheriting Card virtually
class MonsterCard : virtual public Card {
private:
    unsigned int attackPoints;
    unsigned int defencePoints;

    std::ostream &doprint(std::ostream &out) const override;

public:
    MonsterCard(std::string name = "", std::string effect = "", unsigned int rarity = 0, unsigned int attackPoints = 0,
                unsigned int defencePoints = 0);

    unsigned int getAttackPoints() const;

    unsigned int getDefencePoints() const;

    void setAttackPoints(unsigned int newAttackPoints);

    void setDefencePoints(unsigned int newDefencePoints);

    void print() override;

    Card *clone() override;


};

///overloading operators to read/write information about MonsterCard
std::istream &operator>>(std::istream &in, MonsterCard &monster);
//std::ostream& operator<<(std::ostream& out,const MonsterCard& monster);


#endif //HW3_PRAC_MONSTERCARD_HPP
