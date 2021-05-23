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

    ///virtual function that has the same use as operator<<, but its used for polymorphism
    virtual std::ostream &doprint(std::ostream &out) const = 0;

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
    ///operators that compare the rarity of those cards
    bool operator>(const Card &rhs) const;

    bool operator<(const Card &rhs) const;

    ///when using copy constructor and operator= we use clone to clone the data into the new class
    virtual Card *clone() = 0;

    friend std::ostream &operator<<(std::ostream &out, const Card &b);
};

std::ostream &operator<<(std::ostream &out, const Card &b);

#endif //HW3_PRAC_CARD_HPP
