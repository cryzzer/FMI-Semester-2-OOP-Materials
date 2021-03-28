#include "VendingMachine.hpp"
#include "HelpfulFuncs.hpp"

#include <iostream>;
using namespace std;


VendingMachine::VendingMachine(): drinks(nullptr), drinksCount(0), income(0){//constructor
}
VendingMachine::VendingMachine(const VendingMachine& from) {//copy constructor
	copy(from);
}
VendingMachine& VendingMachine::operator=(const VendingMachine& from) {//operator=
	if (this != &from) {
		copy(from);
	}
	return *this;
}
VendingMachine::~VendingMachine() {//destructor
	delete[] drinks;
}

bool VendingMachine::add_drink(const Drink& to_add) {
	//flag if the drink we want to add aldready exists
	bool alreadyExists = checkIfDrinkExists(to_add);

	if (!alreadyExists) {//if it doesn't exist we add it
		//creating new pointer to dynamic Drink array with drinksCount + 1 size
		Drink* newDrinks = new Drink[drinksCount + 1];

		//coppying all the old information to the new arr
		for (int i = 0; i < drinksCount;i++) {
			newDrinks[i] = drinks[i];
		}

		//adding the new drink to thhe last spot
		newDrinks[drinksCount] = to_add;

		//the count of the drinks adds up
		drinksCount++;

		//deleting the old dynamic array, and then reallocating drinks to the new dyn. array
		delete[] drinks;
		drinks = newDrinks;
		
		return true;
	}
	else {
		return false;
	}
}
bool VendingMachine::checkIfDrinkExists(const Drink& to_add) {
	bool alreadyExists = false;//flag that we return at the end
	for (int i = 0; i < drinksCount; i++) {
		int difference = myStrcmp(drinks[i].get_name(), to_add.get_name());
		//if the difference between the two strings is 0 we return true
		if (difference == 0) {
			alreadyExists = true;
			break;
		}
	}
	//otherwise if none strings match return false
	return alreadyExists;
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
	bool alreadyExists = false;//flags if such drink exists and the user has enough money
	bool enoughMoney = false;
	int index = -1;
	for (int i = 0; i < drinksCount; i++) {
		//again checking if there is such drink
		int difference = myStrcmp(drinks[i].get_name(), drink_name);
		if (difference == 0) {
			alreadyExists = true;//flag turns to true
			enoughMoney = (money >= drinks[i].get_price()) ? true : false;//checking if the money is enough 

			index = i;//setting the index that we want to remove the drink from
			break;
		}
	}
	if (alreadyExists) {

		income += money;//adding the money to the machine
		if (enoughMoney) {
			removeDrink(index);//removing drin from index
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		return 2;
	}
}

double VendingMachine::get_income() const {//return income
	return income;
}

//copy all the data from one object to another
void VendingMachine::copy(const VendingMachine& from) {
	drinksCount = from.drinksCount;
	income = from.income;

	delete[] drinks;
	drinks = new Drink[drinksCount];
	for (int i = 0; i < drinksCount; i++) {
		drinks[i] = from.drinks[i];
	}
}


void VendingMachine::removeDrink(const int& index) {
	//creating new pointer to dynamic Drink array with drinksCount - 1 size
	Drink* newDrinks = new Drink[drinksCount - 1];

	//copying all the old data to this index
	for (int i = 0; i < index; i++) {
		newDrinks[i] = drinks[i];
	}
	//after that copy all the data form this index+1 to the end
	for (int i = index; i < drinksCount-1; i++) {
		newDrinks[i] = drinks[i + 1];
	}

	drinksCount--;//lowering the count of drinks in the arrat

	//deleting and reallocating the pointer
	delete[] drinks;
	drinks = newDrinks;
}

//print function
void VendingMachine::printVend() {
	for (int i = 0; i < drinksCount; i++) {
		drinks[i].printDrink();
	}
}