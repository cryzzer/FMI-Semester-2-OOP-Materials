#include "integerOperation.hpp"
#include <iostream>

int main() {
    IntegerOperation test;
    test.insert(5);
    test.insert(3);
    test.insert(7);
    IntegerOperation test2;
    test2.insert(2);
    test2.insert(14);
    test2.insert(4);
    std::cout << test + test2 << std::endl;
    std::cout << test - test2 << std::endl;
    std::cout << test * test2 << std::endl;
}