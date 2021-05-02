//
// Created by User on 28.4.2021 г..
//

#ifndef HW3_PRAC_CARD_HPP
#define HW3_PRAC_CARD_HPP

#include <string>
#include <assert.h>

///Abstract class
class Card {
private:
    std::string name;
    std::string effect;
public:
    Card(std::string name = "", std::string effect = "");
    void setName(std::string newName);
    void setEffect(std::string newEffect);
    std::string getName() const;
    std::string getEffect() const;
    virtual void print() = 0;///pure virtual function
};

#endif //HW3_PRAC_CARD_HPP
