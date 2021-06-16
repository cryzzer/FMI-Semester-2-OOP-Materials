//
// 62518
//
#include <iostream>

#include "Shapes.hpp"

int main() {
    Shapes test;
    test.add(new Circle(2,"red"));
    test.add(new Rectangle(2,4,"blue"));
    test.add(new Circle(2,"red"));
    test.add(new Rectangle(2,4,"blue"));

    std::cout << test.sumRectangleAreas();
}


