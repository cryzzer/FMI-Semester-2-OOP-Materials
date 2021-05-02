//
// Created by User on 28.4.2021 г..
//

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
