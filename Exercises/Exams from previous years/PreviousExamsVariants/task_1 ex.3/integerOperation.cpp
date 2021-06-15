//
// Created by User on 15.6.2021 г..
//
#include <iostream>
#include "integerOperation.hpp"

IntegerOperation::IntegerOperation() : storage(nullptr), size(0), result(0) {
}

IntegerOperation::IntegerOperation(const IntegerOperation &rhs) {
    copyFrom(rhs);
}

IntegerOperation &IntegerOperation::operator=(const IntegerOperation &rhs) {
    if(this != &rhs){
        free();
        copyFrom(rhs);
    }
    return *this;
}

IntegerOperation::~IntegerOperation() {
    free();
}

int IntegerOperation::getResult() const {
    return result;
}

void IntegerOperation::sum() {
    result = 0;
    for (size_t i = 0; i < size; ++i) {
        result += storage[i];
    }
}

void IntegerOperation::subtract() {
    result = 0;
    for (size_t i = 0; i < size; ++i) {
        result -= storage[i];
    }
}

void IntegerOperation::multiply() {
    if(size == 0){
        result = 0;
        return;
    }
    result = 1;
    for (size_t i = 0; i < size; ++i) {
        result *= storage[i];
    }
}

void IntegerOperation::copyFrom(const IntegerOperation &rhs) {
    size = rhs.size;
    for(size_t i = 0; i < size; i++){
        storage[i] = rhs.storage[i];
    }
    result = 0;
}

void IntegerOperation::free() {
    delete[] storage;
    size = 0;
    result = 0;
}

void IntegerOperation::insert(int num) {
    int * temp = new int[size + 1];

    for(size_t i = 0; i < size; i++){
        temp[i] = storage[i];
    }

    temp[size] = num;

    size++;

    delete[] storage;

    storage = temp;
}

int IntegerOperation::operator+(IntegerOperation &rhs) {
    sum();
    rhs.sum();

    return getResult() + rhs.getResult();
}

int IntegerOperation::operator-(IntegerOperation &rhs) {
    subtract();
    rhs.subtract();

    return getResult() - rhs.getResult();
}

int IntegerOperation::operator*(IntegerOperation &rhs) {
    multiply();
    rhs.multiply();

    return getResult() * rhs.getResult();
}


