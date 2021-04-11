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

#include "Backpack.hpp"
#include "Equipment.hpp"

template <class T>
class Inventory {
private:
	T inventory;

public:
	Inventory();
	void setInventory(const T& rhs);

	bool operator==(const Inventory<T>& rhs);
	bool operator!=(const Inventory<T>& rhs);

	//overloading operator<<
	friend std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Money>>& inven);
	friend std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Materials>>& inven);
	friend std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Armor>>& inven);
	friend std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Weapon>>& inven);

};

template<class T>
Inventory<T>::Inventory() {
}

template<class T>
void Inventory<T>::setInventory(const T& rhs) {
	inventory = rhs;
}

template<>
bool Inventory<Backpack<Money>>::operator==(const Inventory<Backpack<Money>>& rhs) {
	return inventory.getSlotsBackpack() == rhs.inventory.getSlotsBackpack();
}

template<>
bool Inventory<Backpack<Materials>>::operator==(const Inventory<Backpack<Materials>>& rhs) {
	return inventory.getSlotsBackpack() == rhs.inventory.getSlotsBackpack();
}

template<>
bool Inventory<Equipment<Armor>>::operator==(const Inventory<Equipment<Armor>>& rhs) {
	return inventory.getSlotsEquipment() == rhs.inventory.getSlotsEquipment();
}

template<>
bool Inventory<Equipment<Weapon>>::operator==(const  Inventory<Equipment<Weapon>>& rhs) {
	return inventory.getSlotsEquipment() == rhs.inventory.getSlotsEquipment();
}


template<>
bool Inventory<Backpack<Money>>::operator!=(const Inventory<Backpack<Money>>& rhs) {
	return inventory.getSlotsBackpack() != rhs.inventory.getSlotsBackpack();
}

template<>
bool Inventory<Backpack<Materials>>::operator!=(const Inventory<Backpack<Materials>>& rhs) {
	return inventory.getSlotsBackpack() != rhs.inventory.getSlotsBackpack();
}

template<>
bool Inventory<Equipment<Armor>>::operator!=(const Inventory<Equipment<Armor>>& rhs) {
	return inventory.getSlotsEquipment() != rhs.inventory.getSlotsEquipment();
}

template<>
bool Inventory<Equipment<Weapon>>::operator!=(const  Inventory<Equipment<Weapon>>& rhs) {
	return inventory.getSlotsEquipment() != rhs.inventory.getSlotsEquipment();
}


std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Money>>& inven) {
	out << inven.inventory.printMatMon();
	return out;
}

std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Materials>>& inven) {
	out << inven.inventory.printMatMon();
	return out;
}

std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Armor>>& inven) {
	out << inven.inventory.printArmWeap();
	return out;
}

std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Weapon>>& inven) {
	out << inven.inventory.printArmWeap();
	return out;
}