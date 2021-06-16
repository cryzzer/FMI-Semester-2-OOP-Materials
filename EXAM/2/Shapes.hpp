//
// 62518
//

#ifndef EXAM_SHAPES_HPP
#define EXAM_SHAPES_HPP
#include "Rectangle.hpp"
#include "Circle.hpp"
#include <vector>

class Shapes {
public:
    void add(Figure* figure);
    double sumRectangleAreas() const;
    double sumCircleAreas() const;
    Figure* operator[](size_t index);

    Shapes() = default;
    ~Shapes();
    Shapes(const Shapes& rhs);
    Shapes& operator=(const Shapes& rhs);
private:
    std::vector<Figure*> figures;

    void copy(const Shapes& rhs);
    void free();
};


#endif //EXAM_SHAPES_HPP
