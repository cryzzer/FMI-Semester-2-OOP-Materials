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

#include "Money.hpp"
#include <cmath>
#include <iostream>

Money::Money() : money(0) {
}
Money::Money(double newMoney) : money(newMoney) {
	MoneyCheck(money);
}

void Money::addMoney(double newMoney) {
	MoneyCheck(newMoney);
	money += newMoney;
}

void Money::MoneyCheck(double& money) {//making shure that there will not be any digits after X.XX....
	double temp = money;
	money = round(temp * 100) / 100;
}

double Money::getMoney() const {
	return money;
}

void Money::print() {
	std::cout << money << '\n';
}