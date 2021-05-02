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

#ifndef HW3_PRAC_PENDULUMCARD_HPP
#define HW3_PRAC_PENDULUMCARD_HPP

#include "monsterCard.hpp"
#include "magicCard.hpp"

///inheriting MonsterCard and MagicCard publicly
class PendulumCard : public MonsterCard, public MagicCard {
private:
    int pendulumScale;
public:
    PendulumCard(std::string name = "", std::string effect = "", unsigned int attackPoints = 0,
                 unsigned int defencePoints = 0, CardType spellType = CardType::SPELL, int pendulumScale = 1);

    int getPendulumScale() const;
    void setPendulumScale(int newPendulumScale);
    void print() final;
};


///overloading operators to read/write information about PendulumCard
std::istream& operator>>(std::istream& in,PendulumCard& pendulum);
std::ostream& operator<<(std::ostream& out,const PendulumCard& pendulum);

#endif //HW3_PRAC_PENDULUMCARD_HPP
