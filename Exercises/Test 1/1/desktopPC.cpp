//
// Created by User on 21.5.2021 г..
//

#include "desktopPC.hpp"
#include <iostream>

DesktopPC::DesktopPC(int power, unsigned int size, double frequency, int price) : power(power), Computer(Type::Desktop,size,frequency,price) {
}

void DesktopPC::print() {
    std::cout << (int)type << "   " << size << "   " << frequency << "   " << price << "   " << power << std::endl;
}
