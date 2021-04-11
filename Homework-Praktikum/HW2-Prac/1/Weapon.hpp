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

#include <vector>
#include <string>
#include <utility>

#include <iostream>
enum class WeaponCategory {//1.2 == possible with 1 hand and 2 hands       1== one handed         2==two handed
	axe,//1.2
	sword,//1.2
	dagger,//1
	mace,//1.2
	staff,//2
	hammer,//1.2
	spear,//1.2
	bow//2
};
enum class WeaponType {
	oneHanded = 1,
	twoHanded = 2
};

class Weapon{
private:
	std::string weaponName = "";
	std::pair<WeaponCategory, WeaponType> weapon = { WeaponCategory::axe,WeaponType::oneHanded };
	std::pair<unsigned int, unsigned int> hitDamage = { 0,1 };
	std::vector<std::string> weaponEffects;
	std::vector<double> weaponEffectsPower;
public:
	Weapon();
	Weapon(std::string newWeaponName,WeaponCategory weaponCategory, WeaponType weaponType, unsigned int hDRange1, unsigned int hDRange2);

	std::string getWeaponName() const;
	std::pair<WeaponCategory, WeaponType> getWeapon() const;
	WeaponType getWeaponType() const;
	std::pair<unsigned int, unsigned int> getHitDamage() const;
	std::vector<std::string> getWeaponEffects() const;
	std::vector<double> getWeaponEffectsPower() const;

	void addNewEffectToWeapon(std::string effect, double effectPower);
	void removeEffectFromWeapon(std::string effect);
	void changeWeaponCategory(WeaponCategory newWeaponCategory);
	void changeWeaponType(WeaponType newWeaponType);
	void changeEPFromEffectInWeapon(std::string currEffect, double newEffPower);

	double weaponScore() const;

	int weaponCategoryCheck(WeaponCategory newWeaponCategory);
	std::string print() const ;
};

