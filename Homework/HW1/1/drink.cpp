#include "drink.hpp"
#include "HelpfulFuncs.hpp"

#include <iostream>;
using namespace std;

Drink::Drink(): name(nullptr), calories(0), quantity(0), price(0) {//default constructor
}

//constructor with parameters
Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) {
	set_name(init_name);
	calories = init_calories;
	quantity = init_quantity;
	price = init_price;
}

//coppy constructor
Drink::Drink(const Drink& rhs) {
	set_name(rhs.name);
	calories = rhs.calories;
	quantity = rhs.quantity;
	price = rhs.price;
}

//operator=
Drink& Drink::operator=(const Drink& rhs) {
	if (this != &rhs) {
		set_name(rhs.name);
		calories = rhs.calories;
		quantity = rhs.quantity;
		price = rhs.price;
	}
	return *this;
}

//destructor
Drink::~Drink() {
	delete[] name;
}

//getters
const char* Drink::get_name() const {
	return name;
}
int Drink::get_calories() const {
	return calories;
}
double Drink::get_quantity() const {
	return quantity;
}
double Drink::get_price() const {
	return price;
}

//setter
void Drink::set_name(const char* new_name) {
	delete[] name;
	int size = myStrlen(new_name);
	name = new char[size + 1];
	myStrcpy(name, new_name, size);
}

void Drink::printDrink() {
	cout << name << "  " << calories << "  " << quantity << "  " << price << endl;
}