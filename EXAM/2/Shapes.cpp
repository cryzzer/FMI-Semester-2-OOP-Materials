//
// 62518
//

#include "Shapes.hpp"

void Shapes::add(Figure *figure) {
    figures.push_back(figure->clone());
}

double Shapes::sumRectangleAreas() const {
    double sum = 0;
    for (size_t i = 0; i < figures.size(); i++) {
        auto recPTR = dynamic_cast<Rectangle*>(figures[i]);
        if(recPTR){
            sum+= recPTR->calculateArea();
        }
    }
    return sum;
}

double Shapes::sumCircleAreas() const {
    double sum = 0;
    for (size_t i = 0; i < figures.size(); i++) {
        auto circlePTR = dynamic_cast<Circle*>(figures[i]);
        if(circlePTR){
            sum+= circlePTR->calculateArea();
        }
    }
    return sum;
}

Figure *Shapes::operator[](size_t index) {
    if (index < figures.size()) {
        return figures[index];
    }
    return nullptr;
}

Shapes::~Shapes() {
    free();
}

Shapes::Shapes(const Shapes &rhs) {
    copy(rhs);
}

Shapes &Shapes::operator=(const Shapes &rhs) {
    if (this != &rhs) {
        free();
        copy(rhs);
    }
    return *this;
}

void Shapes::copy(const Shapes &rhs) {
    for (auto x: rhs.figures) {
        figures.push_back(x->clone());
    }
}

void Shapes::free() {
    for (size_t i = 0; i < figures.size(); i++) {
        delete figures[i];
    }
    figures.clear();
}
