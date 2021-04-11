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

#include "Armor.hpp"
#include "Weapon.hpp"
#include <sstream>

template <class T>
class Equipment {
private:
	std::vector<T> equip;
	int slots = 0;//slots must be at most 24

public:
	Equipment();

	bool isEmptyEquipment();
	bool isFullEquipment();
	void clearEquipment();
	void addNewItem(const T& newItem);
	void removeItem(const std::string& itemName);
	T bestEquipment();
	double bestScore();
	std::string printArmWeap() const;

	int getSlotsEquipment() const;
	
	bool operator==(Equipment<T>& rhs);
	bool operator!=(Equipment<T>& rhs);
};


template<class T>
Equipment<T>::Equipment() : slots(0) {
}

template<class T>
bool Equipment<T>::isEmptyEquipment() {
	return (slots == 0) ? true : false;
}
template<class T>
bool Equipment<T>::isFullEquipment() {
	return (slots == 24) ? true : false;
}
template<class T>
void Equipment<T>::clearEquipment() {
	slots = 0;
	equip.erase(equip.begin(), equip.end());
}

template<class T>
int Equipment<T>::getSlotsEquipment() const {
	return slots;
}


template<class T>
void Equipment<T>::addNewItem(const T& newItem) {//function in class "cries" because there isn't default constructor for 
												 //this function and this code equals with 'void Equipment<T>::addNewItem(const T& newItem) = delete;'
	static_assert(sizeof(T) == 0, "Only specializations of GetGlobal can be used"); // = delete
}

template<>
void Equipment<Armor>::addNewItem(const Armor & newItem) {
	if (slots < 24) {
		bool alreadyExists = false;//flag if the item already exists and if yes, dont add him
		for (size_t i = 0; i < equip.size(); i++) {
			if (equip[i].getArmorName() == newItem.getArmorName()) {
				alreadyExists = true;
				break;
			}
		}
		if (!alreadyExists) {
			equip.push_back(newItem);
			slots++;
		}
		else {
			std::cout << "Item already exists\n";
		}
	}
}

template<>
void Equipment<Weapon>::addNewItem(const Weapon& newItem) {
	if (slots < 24) {
		int addSlots = (int)newItem.getWeaponType();//if 1 or 2 slots to be added
		if ((slots + addSlots) > 24) {//chech if the slots will overflow
			std::cout << "Not enough slots in Backpack\n";
			return;
		}
		bool alreadyExists = false;//flag if the item already exists and if yes, dont add him
		for (size_t i = 0; i < equip.size(); i++) {
			if (equip[i].getWeaponName() == newItem.getWeaponName()) {
				alreadyExists = true;
				break;
			}
		}
		if (!alreadyExists) {
			equip.push_back(newItem);
			slots++;
		}
		else {
			std::cout << "Item already exists\n";
		}
	}
}

template<>
void Equipment<Armor>::removeItem(const std::string& itemName) {
	if (itemName == "") {
		return;
	}
	std::vector<Armor> temp;//copy the vector to a temporary one, then copy each element except the one that we want to remove
	for (size_t i = 0; i < equip.size(); i++) {
		if (equip[i].getArmorName() != itemName) {
			temp.push_back(equip[i]);
		}
	}
	if (equip.size() != temp.size()) {//lower the slots
		slots--;
	}
	equip = temp;
}

template<>
void Equipment<Weapon>::removeItem(const std::string& itemName) {
	if (itemName == "") {
		return;
	}
	int index = 0;
	std::vector<Weapon> temp;//copy the vector to a temporary one, then copy each element except the one that we want to remove
	for (size_t i = 0; i < equip.size(); i++) {
		if (equip[i].getWeaponName() != itemName) {
			temp.push_back(equip[i]);
		}
		else {
			index = i;
		}
	}//checking how much slots we lose
	if (equip.size() != temp.size()) {
		if ((int)equip[index].getWeaponType() == 2) {
			slots -= 2;
		}
		else {
			slots--;
		}
	}
	equip = temp;
}

template<>
Armor Equipment<Armor>::bestEquipment() {
	int index = 0;//retrieving the best equipment
	for (size_t i = 0; i < equip.size(); i++) {
		if (equip[index].gearScore() < equip[i].gearScore()) {
			index = i;
		}
	}
	return equip[index];
}

template<>
Weapon Equipment<Weapon>::bestEquipment() {
	int index = 0;//retrieving the best equipment
	for (size_t i = 0; i < equip.size(); i++) {
		if (equip[index].weaponScore() < equip[i].weaponScore()) {
			index = i;
		}
	}
	return equip[index];
}

template<>
double Equipment<Armor>::bestScore(){
	return this->bestEquipment().gearScore();
}

template<>
double Equipment<Weapon>::bestScore(){
	return this->bestEquipment().weaponScore();
}

template <>//print func for Armor
std::string Equipment<Armor>::printArmWeap()const {
	std::stringstream ss;
	ss << "Slots taken: " << slots << "\n\n";
	for (size_t i = 0; i < equip.size(); i++) {
		ss << i << " Item:\n";
		ss << equip[i].print();
		ss << "\n\n";
	}
	ss << "\n\n\n";
	return ss.str();
}

template <>//print func for Weapon
std::string Equipment<Weapon>::printArmWeap()const {
	std::stringstream ss;
	ss << "Slots taken: " << slots << "\n\n";
	for (size_t i = 0; i < equip.size(); i++) {
		ss << i << " Item:\n";
		ss << equip[i].print();
		ss << "\n\n";
	}
	ss << "\n\n\n";
	return ss.str();
}

template<class T>
bool Equipment<T>::operator==(Equipment<T>& rhs) {
	return (this->bestScore() == rhs.bestScore()) ? true : false;
}

template<class T>
bool Equipment<T>::operator!=(Equipment<T>& rhs) {
	return (this->bestScore() != rhs.bestScore()) ? true : false;
}