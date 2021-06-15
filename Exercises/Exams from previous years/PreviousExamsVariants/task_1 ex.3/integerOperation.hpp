//
// Created by User on 15.6.2021 г..
//

#ifndef VERSION_1_INTEGEROPERATION_HPP
#define VERSION_1_INTEGEROPERATION_HPP


class IntegerOperation {
public:
    IntegerOperation();
    IntegerOperation(const IntegerOperation& rhs);
    IntegerOperation& operator=(const IntegerOperation& rhs);
    ~IntegerOperation();

    int getResult() const;

    void sum();
    void subtract();
    void multiply();

    void insert(int num);

    int operator+(IntegerOperation& rhs);
    int operator-(IntegerOperation& rhs);
    int operator*(IntegerOperation& rhs);

private:
    int* storage;
    int size;

    int result;

    void copyFrom(const IntegerOperation& rhs);
    void free();
};


#endif //VERSION_1_INTEGEROPERATION_HPP
