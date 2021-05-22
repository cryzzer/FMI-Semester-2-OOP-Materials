//
// Created by User on 21.5.2021 г..
//

#ifndef HW4_PRAC_COMPUTER_HPP
#define HW4_PRAC_COMPUTER_HPP

enum class Type{
    Desktop,
    Laptop,
    None
};


class Computer {
public:
    Computer(Type type = Type::None,unsigned int size = 0,double frequency = 0.0,int price = 0);
    double getPriceInEuro() const;
    Type getType() const;
    unsigned int getSize() const;
    double getFrequency()const;
    int getPriceInBGN()const;
    virtual ~Computer();
    virtual void print() = 0;

protected:
    Type type;
    unsigned int size;
    double frequency;
    int price;
};


#endif //HW4_PRAC_COMPUTER_HPP
