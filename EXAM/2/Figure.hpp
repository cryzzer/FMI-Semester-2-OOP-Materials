//
// 62518
//

#ifndef EXAM_FIGURE_HPP
#define EXAM_FIGURE_HPP

#include <string>

class Figure {
public:
    Figure() = default;
    Figure(const std::string& color){
        this->color = color;
    }
    virtual ~Figure() = default;
    virtual Figure* clone() = 0;

    std::string getColor() const{
        return color;
    }
protected:
    std::string color;
};


#endif //EXAM_FIGURE_HPP
