//
// 62518
//

#include "Circle.hpp"

Circle::Circle(double radius, const std::string &color) : Figure(color), radius(radius) {
}

double Circle::getRadius() const {
    return radius;
}

double Circle::calculateArea() const {
    const double PI = 3.14;
    return radius * radius * PI;
}

Figure *Circle::clone() {
    return new Circle(*this);
}
