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
class MonsterCard{
private:
	char* monsterName = nullptr;
	int atkPoints = 0;
	int defPoints = 0;

public:
	MonsterCard(const char* monsterName = "", const int& atkpoints = 0, const int& defpoints = 0);//constructor
	~MonsterCard();//destructor
	MonsterCard(const MonsterCard& rhs);//copy constructor
	MonsterCard& operator=(const MonsterCard& rhs);//operator=

	//getters
	char* getMonsterName();
	int getAtkPoints();
	int getDefPoints();

	//setter
	void setMonsterName(const char* newMonName);
	void setAtkPoints(const int& newAtkPoints);
	void setDefPoints(const int& newDefPoints);

	//print
	void printMon();
};

