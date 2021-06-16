//
// 62518
//

#include "Rectangle.hpp"

Rectangle::Rectangle(double  length, double  width, const std::string &color) : Figure(color),length(length),width(width) {
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::calculateArea() const {
    return length*width;
}

Figure *Rectangle::clone() {
    return new Rectangle(*this);
}
