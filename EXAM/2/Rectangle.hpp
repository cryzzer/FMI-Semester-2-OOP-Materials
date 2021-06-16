//
// 62518
//

#ifndef EXAM_RECTANGLE_HPP
#define EXAM_RECTANGLE_HPP

#include "Figure.hpp"

class Rectangle: public Figure{
public:
    Rectangle(double  length = 0,double  width = 0, const std::string& color = "");
    double getLength() const;
    double getWidth() const;
    double calculateArea() const;
    Figure* clone() override;
private:
    double  length;
    double  width;
};


#endif //EXAM_RECTANGLE_HPP
