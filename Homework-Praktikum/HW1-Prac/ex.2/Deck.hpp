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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class Deck{
private:
	const int MAX_DECK_SIZE = 21;
	MonsterCard* monsterDeck = new MonsterCard[MAX_DECK_SIZE];//1st method
	MagicCard* spellDeck = new MagicCard[MAX_DECK_SIZE];      //2nd method

	//arrays for checking on which position a card is already been entered so when adding a new card 
	//not using index we prevent replacing an already existing one
	int monsterCheckArr[22] = { 0 }; 
	int spellCheckArr[22] = { 0 };

	//for function where we have to return the count of the monsters/spells
	int monsterCount = 0;
	int spellCount = 0;


public:
	Deck();//constructor
	~Deck();//destructor
	Deck(const Deck& rhs);//copy constructor
	Deck& operator=(const Deck& rhs);//operator=

	int countSpellsInDeck();                       //3rd method
	int countMonstersInDeck();                     //4th method

	void addNewSpell(const MagicCard& newSpell);   //5th method
	void addNewMonster(const MonsterCard& newMonCard);//6th method

	void changeSpellFromIndex(const int& index, const MagicCard& newSpell);//7th method
	void addMonsterToIndex(const int& index, const MonsterCard& newMonCard);//8th method

	//printing functions 
	void printMonsterDeck();
	void printSpellDeck();
};

