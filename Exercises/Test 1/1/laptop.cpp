//
// Created by User on 21.5.2021 г..
//

#include "laptop.hpp"
#include <iostream>

Laptop::Laptop(bool inStock, unsigned int size, double frequency, int price) : inStock(inStock), Computer(Type::Laptop,size, frequency,price) {
}

void Laptop::print() {
    std::cout << (int)type << "   " << size << "   " << frequency << "   " << price << "   " <<  inStock << std::endl;
}
