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
#include "MagicCard.hpp"
#include "HelpfulFuncs.hpp"

#include <iostream>
using namespace std;


//setting parameters in constructor
MagicCard::MagicCard(const char* newMagName, const char* newEffect, SpellType spelltype){
	setMagName(newMagName);
	setEffect(newEffect);
	setSpelltype(spelltype);
}

//deleting dynamic char arrays
MagicCard::~MagicCard() {
	delete[] magicCardName;
	delete[] effect;
}
//copy constructor
MagicCard::MagicCard(const MagicCard& rhs) {
	setMagName(rhs.magicCardName);
	setEffect(rhs.effect);
	setSpelltype(rhs.spelltype);
}
//operator=
MagicCard& MagicCard::operator=(const MagicCard& rhs) {
	if (this != &rhs) {
		setMagName(rhs.magicCardName);
		setEffect(rhs.effect);
		setSpelltype(rhs.spelltype);
	}
	return *this;
}
//getters
char* MagicCard::getMagName() {
	return this->magicCardName;
}
char* MagicCard::getEffect() {
	return this->effect;
}

//setters
void MagicCard::setMagName(const char* newMagName) {
	delete[] this->magicCardName;
	int size1 = myStrlen(newMagName);
	this->magicCardName = new char[size1 + 1];
	myStrcpy(this->magicCardName, newMagName, size1);
}
void MagicCard::setEffect(const char* newEffect) {
	delete[] this->effect;
	int size1 = myStrlen(newEffect);
	this->effect = new char[size1 + 1];
	myStrcpy(this->effect, newEffect, size1);
}
void MagicCard::setSpelltype(SpellType spelltype) {
	this->spelltype = spelltype;
}

//print
void MagicCard::printSpell() {
	cout << magicCardName << "    " << effect << "      " << spelltype << endl;
}
