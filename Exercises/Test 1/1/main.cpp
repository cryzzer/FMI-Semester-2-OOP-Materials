//
// Created by User on 21.5.2021 г..
//
#include <iostream>
#include "laptop.hpp"
#include "desktopPC.hpp"

int main(){
    Laptop l1(true,500,4.7,25);
    l1.print();
    std::cout << l1.getPriceInEuro();
    std::cout << "\n\n" << (int)l1.getType();
}