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

class Money{
private:
	double money = 0;

public:
	Money();
	Money(double newMoney);

	void addMoney(double newMoney);
	double getMoney() const ;
	void MoneyCheck(double& money);
	void print();
};

