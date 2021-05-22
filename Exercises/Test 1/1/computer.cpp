//
// Created by User on 21.5.2021 г..
//

#include "computer.hpp"

Computer::Computer(Type type, unsigned int size, double frequency, int price) : type(type), size(size), frequency(frequency), price(price) {
}

Computer::~Computer() {
}

double Computer::getPriceInEuro() const {
    return price * 0.5113;
}

Type Computer::getType() const {
    return type;
}

unsigned int Computer::getSize() const {
    return size;
}

double Computer::getFrequency() const {
    return frequency;
}

int Computer::getPriceInBGN() const {
    return price;
}
