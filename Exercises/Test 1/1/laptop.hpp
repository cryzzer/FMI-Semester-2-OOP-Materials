//
// Created by User on 21.5.2021 г..
//

#ifndef HW4_PRAC_LAPTOP_HPP
#define HW4_PRAC_LAPTOP_HPP
#include "computer.hpp"


class Laptop : public Computer {
public:
    Laptop(bool inStock = true,unsigned int size = 0,double frequency = 0.0,int price = 0);
    void print() override;

private:
    bool inStock;

};


#endif //HW4_PRAC_LAPTOP_HPP
