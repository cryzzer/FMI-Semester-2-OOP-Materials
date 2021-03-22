#include "Car.hpp"
#include "HelpfulFuncs.hpp"
#include <iostream>

using namespace std;

Car::Car(const char model_[], const char regNum_[], const char color_[]) {
	int size1 = myStrlen(model_);
	myStrcpy(this->model, model_, size1);
	int size2 = myStrlen(regNum_);
	myStrcpy(this->regNum, regNum_, size2);
	int size3 = myStrlen(color_);
	myStrcpy(this->color, color_, size3);
}

Car::Car(const Car& rhs) {
	int size1 = myStrlen(rhs.model);
	myStrcpy(this->model, rhs.model, size1);
	int size2 = myStrlen(rhs.regNum);
	myStrcpy(this->regNum, rhs.regNum, size2);
	int size3 = myStrlen(rhs.color);
	myStrcpy(this->color, rhs.color, size3);
}

void Car::setModel(const char newModel[]) {
	int size = myStrlen(newModel);
	myStrcpy(this->model, newModel, size);
}
void Car::setRegNum(const char newRegNum[]) {
	int size = myStrlen(newRegNum);
	myStrcpy(this->regNum, newRegNum, size);
}
void Car::setColor(const char newColor[]) {
	int size = myStrlen(newColor);
	myStrcpy(this->color, newColor, size);
}

void Car::printCar() {
	cout << model << ' ' << regNum << ' ' << color << endl;
}