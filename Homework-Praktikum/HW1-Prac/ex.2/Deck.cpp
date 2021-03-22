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
#include "Deck.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"



//constructor
Deck::Deck(){}

//deleting the dynamic MonsterCard/SpellCard arrays
Deck::~Deck() {
	delete[] monsterDeck;
	delete[] spellDeck;
}

//copy constructor
Deck::Deck(const Deck& rhs) {
	for (int i = 0; i < MAX_DECK_SIZE; i++) {
		this->monsterDeck[i] = rhs.monsterDeck[i];
		this->spellDeck[i] = rhs.spellDeck[i];
	}
	for (int i = 0; i < 22; i++) {
		this->monsterCheckArr[i] = rhs.monsterCheckArr[i];
		this->spellCheckArr[i] = rhs.spellCheckArr[i];
	}
	this->monsterCount = rhs.monsterCount;
	this->spellCount = rhs.spellCount;
}

//operator=
Deck& Deck::operator=(const Deck& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < MAX_DECK_SIZE; i++) {
			this->monsterDeck[i] = rhs.monsterDeck[i];
			this->spellDeck[i] = rhs.spellDeck[i];
		}
		for (int i = 0; i < 22; i++) {
			this->monsterCheckArr[i] = rhs.monsterCheckArr[i];
			this->spellCheckArr[i] = rhs.spellCheckArr[i];
		}
		this->monsterCount = rhs.monsterCount;
		this->spellCount = rhs.spellCount;
	}
	return *this;
}

//returning the count of monsters/spells in deck
int Deck::countSpellsInDeck() {
	return this->spellCount;
}
int Deck::countMonstersInDeck() {
	return this->monsterCount;
}

//adding a new spell
void Deck::addNewSpell(const MagicCard& newSpell) {
	for (int i = 0; i < 20; i++) {
		//if there hasnt been entered a spell turn the element to 1, so next time there won't be added spell on this index
		if (spellCheckArr[i] == 0) {
			spellDeck[i] = newSpell;

			spellCheckArr[i] = 1;
			spellCount++;//adding the count
			break;
		}
	}
}

void Deck::addNewMonster(const MonsterCard& newMonCard) {
	for (int i = 0; i < 20; i++) {
		if (monsterCheckArr[i] == 0) {//simillar logic to "void Deck::addNewSpell"
			monsterDeck[i] = newMonCard;

			monsterCheckArr[i] = 1;
			monsterCount++;
			break;
		}
	}
}

void Deck::changeSpellFromIndex(const int& index, const MagicCard& newSpell) {
	spellDeck[index] = newSpell;
	if (spellCheckArr[index] == 0) {//simillar logic to "void Deck::addNewSpell"
		spellCheckArr[index] = 1;
		spellCount++;
	}
}
void Deck::addMonsterToIndex(const int& index, const MonsterCard& newMonCard) {
	monsterDeck[index] = newMonCard;
	if (monsterCheckArr[index] == 0) {//simillar logic to "void Deck::addNewSpell"
		monsterCheckArr[index] = 1;
		monsterCount++;
	}
}

//prints
void Deck::printMonsterDeck() {
	for (int i = 0; i < MAX_DECK_SIZE; i++) {
		monsterDeck[i].printMon();
	}
}

void Deck::printSpellDeck() {
	for (int i = 0; i < MAX_DECK_SIZE; i++) {
		spellDeck[i].printSpell();
	}
}
