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
#include "Duelist.hpp"
#include "Deck.hpp"
#include "HelpfulFuncs.hpp"




Duelist::Duelist(const char* newDuelistName,const Deck& newDeck) {//constructor
	setDuelistName(newDuelistName);
	this->newDeck = newDeck;
}
Duelist::~Duelist() {//deconstructor
	delete[] duelistName;
}

Duelist::Duelist(const Duelist& rhs) {//copy constructor
	setDuelistName(rhs.duelistName);
	this->newDeck = rhs.newDeck;
}
Duelist& Duelist::operator=(const Duelist& rhs) {//operator=
	if (this != &rhs) {
		setDuelistName(rhs.duelistName);
		this->newDeck = rhs.newDeck;
	}
	return *this;
}

char* Duelist::getDuelistName() {//getter
	return this->duelistName;
}

void Duelist::setDuelistName(const char* newDuelistName) {//setter
	delete[] duelistName;
	int size = myStrlen(newDuelistName);
	duelistName = new char[size + 1];
	myStrcpy(duelistName, newDuelistName, size);
}

//returning the count of the monsters/spells in the deck
int Duelist::countForSpellsInDeck() {
	return newDeck.countSpellsInDeck();
}
int Duelist::countForMonstersInDeck() {
	return newDeck.countMonstersInDeck();
}

//adding new monster/spell to the first free space
void Duelist::addNewSpellToDeck(const MagicCard& newSpell) {
	newDeck.addNewSpell(newSpell);
}
void Duelist::addNewMonsterToDeck(const MonsterCard& newMonCard) {
	newDeck.addNewMonster(newMonCard);
}

//adding new monster/spell to the desired index
void Duelist::changeSpellFromIndexInDeck(const int& index, const MagicCard& newSpell) {
	newDeck.changeSpellFromIndex(index, newSpell);
}
void Duelist::addMonsterToIndexInDeck(const int& index, const MonsterCard& newMonCard) {
	newDeck.addMonsterToIndex(index, newMonCard);
}

//printing
void Duelist::printMonsterDeckFromDeck() {
	newDeck.printMonsterDeck();
}
void Duelist::printSpellDeckFromDeck() {
	newDeck.printSpellDeck();
}