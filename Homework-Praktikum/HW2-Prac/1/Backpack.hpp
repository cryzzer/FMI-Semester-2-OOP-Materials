#pragma once

/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 1
* @compiler VC
*/

#include "Materials.hpp"
#include "Money.hpp"
#include <vector>
#include <iostream>
#include <sstream>

template <class T>
class Backpack {
private:
	std::vector<T> backpack;
	int slots = 0;

	void addCorrectlyQuantityWEAPON_ONLY(const T& newItem);//function that fills each slot with the max capacity of the slot, depending of the type
public:
	Backpack();

	int getSlotsBackpack() const;

	bool isEmptyBackpack();
	bool isFullBackpack();
	void emptyTheBackpack();
	void addItemBackpack(const T& newItem);
	void removeItemBackpack(const T& typeAndQuantity);

	std::string printMatMon() const ;
};

template <class T>
Backpack<T>::Backpack() : slots(0) {
}

template<class T>
int Backpack<T>::getSlotsBackpack() const {//getter for slots
	return slots;
}

template <class T>
bool Backpack<T>::isEmptyBackpack() {
	return (slots == 0 && backpack.empty()) ? true : false;
}

template<>
bool Backpack<Money>::isFullBackpack() {
	return false;
}

template<>
bool Backpack<Materials>::isFullBackpack() {
	return (slots == 16) ? true : false;
}

template<class T>
void Backpack<T>::emptyTheBackpack() {
	slots = 0;
	backpack.erase(backpack.begin(), backpack.end());//deleting the data from the vector
}

template<class T>
void Backpack<T>::addItemBackpack(const T& newItem) {//function in class "cries" because there isn't default constructor for 
												 //this function and this code equals with 'void Backpack<T>::addItemBackpack(const T& newItem) = delete;'
	static_assert(sizeof(T) == 0, "Only specializations of GetGlobal can be used"); // = delete
}


template<>
void Backpack<Money>::addItemBackpack(const Money& newItem) {
	//checking if there is existing Money on index 0, if not `pushback`, if yes, add the money to the main money
	if (backpack.empty()) {
		backpack.push_back(newItem);
		return;
	}
	backpack[0].addMoney(newItem.getMoney());
}

template<>
void Backpack<Materials>::addItemBackpack(const Materials& newItem) {
	//checking if the slots are full, but there may be available space
	if (slots == 16) {
		bool availableSpace = false;//flag for available space
		int capacity;
		if (newItem.getMatType() == MaterialsType::herbs || newItem.getMatType() == MaterialsType::cloth || newItem.getMatType() == MaterialsType::ores) {
			capacity = 20;
		}
		else {
			capacity = 10;
		}

		for (size_t i = 0; i < backpack.size();i++) {
			if (backpack[i].getMatType() == newItem.getMatType() && backpack[i].getQuantity() < capacity) {
				availableSpace = true;
				break;
			}
		}
		if (availableSpace) {//if there is we call this funtion to add as much material as possibe
			addCorrectlyQuantityWEAPON_ONLY(newItem);
		}
	}
	else {//if slots aren't full, call this func again
		addCorrectlyQuantityWEAPON_ONLY(newItem);
	}

}

template<>
void Backpack<Materials>::addCorrectlyQuantityWEAPON_ONLY(const Materials& newItem) {
	if (newItem.getQuantity() < 1) {//if the quantity of the material is below 1, no need to add it to the slots
		return;
	}

	int maxQuantityInSlot;//deciding chat is the max capacity in the slot for this mat. type
	if (newItem.getMatType() == MaterialsType::herbs || newItem.getMatType() == MaterialsType::cloth || newItem.getMatType() == MaterialsType::ores) {
		maxQuantityInSlot = 20;
	}
	else {
		maxQuantityInSlot = 10;
	}

	std::vector<Materials> temp = backpack;//creating temporary vector, which will be filled with the material
	int quantityLeft = newItem.getQuantity();//the quantity left to be added
	
	while (quantityLeft > 0) {//while there isn't any quantity left to be added we cycle the loop
		bool alreadyFullOrMissing = true;//again flags if there is already a material but with still available space to be added
		int index = 0;

		for (size_t i = 0; i < temp.size(); i++) {
			if (temp[i].getMatType() == newItem.getMatType() && temp[i].getQuantity() < maxQuantityInSlot) {
				alreadyFullOrMissing = false;//if there is availabe spot take the index of that spot
				index = i;
				break;
			}
		}

		if (!alreadyFullOrMissing) {
			int checker = maxQuantityInSlot - temp[index].getQuantity();//check how much space is availabe
			if (quantityLeft < checker) {//if the `quantityLeft` is lower add it, and then make `quantityLeft` = 0
				temp[index].addQuantity(quantityLeft);
				quantityLeft -= checker;
			}
			else {//else fill the availabe space and take the filled quantity of the `quantityLeft`
				temp[index].addQuantity(checker);
				quantityLeft -= checker;
			}
		}
		else {
			Materials filler(newItem.getMatType(), 0);//if there isn't any availabe space, create a new `Materials` object

			if (quantityLeft <= maxQuantityInSlot) {//here decide hwo to fill the `Quantity` section
				filler.addQuantity(quantityLeft);
				temp.push_back(filler);
				quantityLeft -= maxQuantityInSlot;
			}
			else {
				filler.addQuantity(maxQuantityInSlot);
				temp.push_back(filler);
				quantityLeft -= maxQuantityInSlot;
			}
		}
	}

	//empty the vector and make the slots 0
	emptyTheBackpack();

	//coppy the temp vector to our main one, but with at most 16 slots
	for (size_t i = 0;i < temp.size(); i++) {
		if (i > 15) {
			break;
		}
		backpack.push_back(temp[i]);
	}
	slots = backpack.size();
}

template<>
void Backpack<Money>::removeItemBackpack(const Money& typeAndQuantity) {
	if (backpack.empty()) {
		std::cout << "Can't remove any items, backpack is empty!\n";
		return;
	}
	if (typeAndQuantity.getMoney() >= backpack[0].getMoney()) {
		int zeroMoney = backpack[0].getMoney();//make the money 0
		backpack[0].addMoney(-zeroMoney);
	}
	else {
		backpack[0].addMoney(-typeAndQuantity.getMoney());//remove any number of money
	}
}

template<>
void Backpack<Materials>::removeItemBackpack(const Materials& typeAndQuantity) {
	int arr[4] = { 0 };//create an array with all 4 materials
	for (size_t i = 0; i < backpack.size(); i++) {
		arr[(int)backpack[i].getMatType()] += backpack[i].getQuantity();//fill the array with the quantity of each material type
	}

	if (typeAndQuantity.getQuantity() >= arr[(int)typeAndQuantity.getMatType()]) {//here exclude the the quantity that you have entered to remove
		arr[(int)typeAndQuantity.getMatType()] = 0;
	}
	else {
		arr[(int)typeAndQuantity.getMatType()] -= typeAndQuantity.getQuantity();
	}

	emptyTheBackpack();//empty the backpack and then after that create a new object for all the types, then add them to the vector

	Materials herb(MaterialsType::herbs, arr[0]);
	addItemBackpack(herb);
	Materials ore(MaterialsType::ores, arr[1]);
	addItemBackpack(ore);
	Materials cloth(MaterialsType::cloth, arr[2]);
	addItemBackpack(cloth);
	Materials essence(MaterialsType::essence, arr[3]);
	addItemBackpack(essence);
}


template<>//print function for money
std::string Backpack<Money>::printMatMon() const {
	std::stringstream ss;
	for (size_t i = 0; i < backpack.size();i++) {
		ss << "Money: " << backpack[i].getMoney() << " (gold,silver)\n";
	}
	ss << "Slots taken: " << slots << std::endl;
	return ss.str();
}

template<>//print function for materials
std::string Backpack<Materials>::printMatMon() const {
	std::stringstream ss;
	ss << "List of Items:\n\n";
	for (size_t i = 0; i < backpack.size();i++) {
		ss << "Slot :" << i << "  Material: " << (int)backpack[i].getMatType() << "  quantity: " << backpack[i].getQuantity() << std::endl;
	}
	ss << "Slots taken: " << slots << std::endl;
	return ss.str();
}

