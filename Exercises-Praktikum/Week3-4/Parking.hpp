#pragma once

#ifndef Parking
#define park 1

#include "Car.hpp"

class Parking {
private:
	char* companyName = nullptr;
	Car* cars = nullptr;
	int carsCount = 0;

public:
	//Parking(const char compName[] = nullptr, Car cars[] = nullptr, int count = 0);
	Parking();

	Parking(const char* name, Car* cars, const int& count);

	Parking(const Parking& rhs);
	~Parking();

	void setCompName(char newName[]);
	void setCars(Car newCars[], int& newCount);

	char* getCompName();
	Car* getCars();
	int getCount();

	void addCar(const Car& newCar);
	void removeCar(const int& index);
	void printParkingCars();
	void addCarAtIndex(const int& index, const Car& addCar);

	char* findCar(const char* number);
};


#endif // !Parking
