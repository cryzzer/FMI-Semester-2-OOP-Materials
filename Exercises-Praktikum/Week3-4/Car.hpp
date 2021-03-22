#pragma once
#ifndef Car
#define car 1

class Car {
private:
	char model[200];
	char regNum[200];
	char color[200];

public:
	Car(const char model_[] = "Lada", const char regNum_[] = "AA 0000 AA", const char color_[] = "white");

	Car(const Car& rhs);

	char* getModel() {
		return this->model;
	}
	char* getRegNum() {
		return this->regNum;
	}
	char* getColor() {
		return this->color;
	}

	void setModel(const char newModel[]);
	void setRegNum(const char newRegNum[]);
	void setColor(const char newColor[]);

	void printCar();
};


#endif // Car
