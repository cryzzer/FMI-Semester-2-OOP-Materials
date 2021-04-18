#pragma once

#include <vector>


class Vector4D {

public:
    Vector4D();
    Vector4D(double el1, double el2, double el3, double el4);

    double& operator[](int index);//used for mutation/ taking the index of the vector

    Vector4D operator+(const Vector4D& rhs) const;
    Vector4D& operator+=(const Vector4D& rhs);

    Vector4D operator-(const Vector4D& rhs) const;
    Vector4D& operator-=(const Vector4D& rhs);

    Vector4D operator*(const Vector4D& rhs) const;
    Vector4D& operator*=(const Vector4D& rhs);
    Vector4D operator*(double value)const;
    Vector4D& operator*=(double value);

    Vector4D operator/(const Vector4D& rhs) const;
    Vector4D& operator/=(const Vector4D& rhs);

    bool operator==(const Vector4D& rhs) const;
    bool operator!=(const Vector4D& rhs) const;

    bool operator>(const Vector4D& rhs) const;
    bool operator>=(const Vector4D& rhs) const;

    bool operator<(const Vector4D& rhs) const;
    bool operator<=(const Vector4D& rhs) const;

    bool operator!() const;// vector full with 0-s

    Vector4D operator-() const;//negation

    void printVec();
private:
    std::vector<double> vec;
};
