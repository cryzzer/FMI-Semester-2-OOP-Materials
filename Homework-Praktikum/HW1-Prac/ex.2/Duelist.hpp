#pragma once
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

class Duelist{
private:
	char* duelistName = nullptr;
	Deck newDeck;
public:
	Duelist(const char* newDuelistName = "", const Deck& newDeck = Deck());//constructor
	~Duelist();//destructor
	Duelist(const Duelist& rhs);//copy constructor
	Duelist& operator=(const Duelist& rhs);//operator=
	//getter and setter
	char* getDuelistName();
	void setDuelistName(const char* newDuelistName);

	int countForSpellsInDeck();                       //3rd method
	int countForMonstersInDeck();                     //4th method

	void addNewSpellToDeck(const MagicCard& newSpell);   //5th method
	void addNewMonsterToDeck(const MonsterCard& newMonCard);//6th method

	void changeSpellFromIndexInDeck(const int& index, const MagicCard& newSpell);//7th method
	void addMonsterToIndexInDeck(const int& index, const MonsterCard& newMonCard);//8th method

	//prints
	void printMonsterDeckFromDeck();
	void printSpellDeckFromDeck();
};

