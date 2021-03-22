/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 2
* @compiler VC
*/
#include "MonsterCard.hpp"
#include "HelpfulFuncs.hpp"

#include <iostream>
using namespace std;


//setting parameters in constructor
MonsterCard::MonsterCard(const char* monsterName, const int& atkpoints, const int& defpoints) {
	setMonsterName(monsterName);

	this->atkPoints = atkpoints;
	this->defPoints = defpoints;
}
//deleting dynamic char arrays
MonsterCard::~MonsterCard() {
	delete[] monsterName;
}
//copy constructor
MonsterCard::MonsterCard(const MonsterCard& rhs) {
	setMonsterName(rhs.monsterName);
	atkPoints = rhs.atkPoints;
	defPoints = rhs.defPoints;
}
//operator=
MonsterCard& MonsterCard::operator=(const MonsterCard& rhs) {
	if (this != &rhs) {
		setMonsterName(rhs.monsterName);
		atkPoints = rhs.atkPoints;
		defPoints = rhs.defPoints;
	}
	return *this;
}
//getters
char* MonsterCard::getMonsterName() {
	return this->monsterName;
}
int MonsterCard::getAtkPoints() {
	return this->atkPoints;
}
int MonsterCard::getDefPoints() {
	return this->defPoints;
}
//setters
void MonsterCard::setMonsterName(const char* newMonName) {
	delete[] this->monsterName;
	int size = myStrlen(newMonName);
	this->monsterName = new char[size + 1];
	myStrcpy(monsterName, newMonName, size);
}
void MonsterCard::setAtkPoints(const int& newAtkPoints) {
	this->atkPoints = newAtkPoints;
}
void MonsterCard::setDefPoints(const int& newDefPoints) {
	this->defPoints = newDefPoints;
}

//print
void MonsterCard::printMon() {
	cout << monsterName << "    " << atkPoints << "      " << defPoints << endl;
 }

