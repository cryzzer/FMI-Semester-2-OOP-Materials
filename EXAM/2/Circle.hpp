//
// 62518
//

#ifndef EXAM_CIRCLE_HPP
#define EXAM_CIRCLE_HPP

#include "Figure.hpp"

class Circle : public Figure{
public:
    Circle(double radius = 0, const std::string& color = "");
    double  getRadius() const;
    double calculateArea() const;
    Figure* clone() override;
private:
    double  radius;
};


#endif //EXAM_CIRCLE_HPP
