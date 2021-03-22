
#include "Parking.hpp"
#include "HelpfulFuncs.hpp"

Parking::Parking() : companyName(nullptr), cars(nullptr), carsCount(0) {
}

Parking::Parking(const char *compName, Car* cars,const int& count){
	this->carsCount = count;

	int sizeCompName = myStrlen(compName);
	this->companyName = new char[sizeCompName + 1];   
	myStrcpy(this->companyName, compName, sizeCompName);

	this->cars = new Car[count];
	for (int i = 0; i < count; i++) {
		this->cars[i] = cars[i];
	}
}

Parking::Parking(const Parking& rhs) {
	this->carsCount = rhs.carsCount;

	delete[] companyName;
	int sizeCompName = myStrlen(rhs.companyName);
	this->companyName = new char[sizeCompName + 1];
	myStrcpy(this->companyName, rhs.companyName, sizeCompName);

	delete[] cars;
	this->cars = new Car[carsCount];
	for (int i = 0; i < carsCount; i++) {
		this->cars[i] = rhs.cars[i];
	}
}
Parking::~Parking() {
	delete[] companyName;
	delete[] cars;
}

void Parking::setCompName(char newName[]) {
	delete[] companyName;
	int sizeNewName = myStrlen(newName);
	companyName = new char[sizeNewName + 1];
	myStrcpy(companyName, newName, sizeNewName);
}
void Parking::setCars(Car newCars[], int& newCount) {
	if (newCount > 0) {
		carsCount = newCount;
	}
	delete[] cars;
	cars = new Car[carsCount];
	for (int i = 0; i < carsCount; i++) {
		cars[i] = newCars[i];
	}
}

char* Parking::getCompName() {
	return this->companyName;
}
Car* Parking::getCars() {
	return this->cars;
}
int Parking::getCount() {
	return this->carsCount;
}

void Parking::addCar(const Car& newCar) {
	Car* newCarArr = new Car[carsCount + 1];

	for (int i = 0; i < carsCount; i++) {
		newCarArr[i] = cars[i];
	}

	newCarArr[carsCount] = newCar;
	carsCount++;

	delete[] cars;
	cars = newCarArr;
}
void Parking::removeCar(const int& index) {
	Car* newCarArr = new Car[carsCount - 1];

	for (int i = 0; i < index; i++) {
		newCarArr[i] = cars[i];
	}
	for (int i = index; i < carsCount - 1; i++) {
		newCarArr[i] = cars[i + 1];
	}
	carsCount--;
	delete[] cars;
	cars = newCarArr;
}
void Parking::printParkingCars() {
	for (int i = 0; i < carsCount; i++) {
		cars[i].printCar();
	}
}
void Parking::addCarAtIndex(const int& index, const Car & addCar) {
	Car* newCarArr = new Car[carsCount + 1];

	for (int i = 0; i < index ; i++) {
		newCarArr[i] = cars[i];
	}
	newCarArr[index] = addCar;

	for (int i = index + 1;i < carsCount + 1; i++) {
		newCarArr[i] = cars[i - 1];
	}
	carsCount++;
	delete[] cars;
	cars = newCarArr;
}
char* Parking::findCar(const char* number) {
	for (int i = 0; i < carsCount; i++) {
		if (myStrcmp(cars[i].getRegNum(), number) == 0) {
			return cars[i].getModel();
		}
	}
}


