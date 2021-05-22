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
#ifndef HW3_PRAC_CARD_HPP
#define HW3_PRAC_CARD_HPP

#include <string>
#include <assert.h>

///Abstract class
class Card {
private:
    std::string name;
    std::string effect;
    unsigned int rarity;
public:
    Card(std::string name = "", std::string effect = "", unsigned int rarity = 0);
    virtual ~Card();

    void setName(std::string newName);
    void setEffect(std::string newEffect);
    void setRarity(unsigned int newRarity);

    std::string getName() const;
    std::string getEffect() const;
    unsigned int getRarity() const;

    virtual void print() = 0;///pure virtual function
    bool operator>(const Card& rhs);
    bool operator<(const Card& rhs);

    virtual Card* clone() = 0;
};

#endif //HW3_PRAC_CARD_HPP
