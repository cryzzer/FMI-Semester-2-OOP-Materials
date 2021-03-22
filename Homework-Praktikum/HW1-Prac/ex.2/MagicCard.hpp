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
enum SpellType {//adding 3 possible spelltypes
	spell = 0,
	trap = 1,
	buff = 2
};
class MagicCard{
private:
	char* magicCardName = nullptr;
	char* effect = nullptr;
	SpellType spelltype;
	
public:
	MagicCard(const char* newMagName = "", const char* newEffect= "", SpellType spelltype = spell);//constructor
	~MagicCard();//destructor
	MagicCard(const MagicCard& rhs);//copy constructor
	MagicCard& operator=(const MagicCard& rhs);//operator=

	//getters
	char* getMagName();
	char* getEffect();
	//get spelltype?

	//setter
	void setMagName(const char* newMagName);
	void setEffect(const char* newEffect);
	void setSpelltype(SpellType spelltype);

	//print function
	void printSpell();
};
