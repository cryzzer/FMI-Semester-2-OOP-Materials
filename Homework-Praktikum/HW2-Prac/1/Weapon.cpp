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

#include "Weapon.hpp"
#include <tuple>
#include <iostream>
#include <sstream>
Weapon::Weapon() : weaponName(""){
	weapon = std::make_pair(WeaponCategory::axe, WeaponType::oneHanded);
	hitDamage = std::make_pair(0, 1);
}
Weapon::Weapon(std::string newWeaponName, WeaponCategory weaponCategory, WeaponType weaponType, unsigned int hDRange1, unsigned int hDRange2) {
	weaponName = newWeaponName;
	switch (weaponCategoryCheck(weaponCategory)) {//when making the weapon check for the specific weapons that can be only 1-handed or 2-handed
	case 0:
		weapon = std::make_pair(weaponCategory, weaponType);
		break;
	case 1:
		weapon = std::make_pair(weaponCategory, WeaponType::oneHanded);
		break;
	case 2:
		weapon = std::make_pair(weaponCategory, WeaponType::twoHanded);
		break;
	default:
		break;
	}
	hitDamage = std::make_pair(hDRange1, hDRange2);
}

std::string Weapon::getWeaponName() const {
	return weaponName;
}
std::pair<WeaponCategory, WeaponType> Weapon::getWeapon() const {
	return weapon;
}
WeaponType Weapon::getWeaponType() const {
	return weapon.second;
}
std::pair<unsigned int, unsigned int> Weapon::getHitDamage() const {
	return hitDamage;
}
std::vector<std::string> Weapon::getWeaponEffects() const {
	return weaponEffects;
}
std::vector<double> Weapon::getWeaponEffectsPower() const {
	return weaponEffectsPower;
}

void Weapon::addNewEffectToWeapon(std::string effect, double effectPower) {
	if (effect != "" && effectPower > 0) {//if effect already exists, just change his power
		bool alreadyExists = false;
		for (size_t i = 0; i < weaponEffects.size(); i++) {
			if (weaponEffects[i] == effect) {
				weaponEffectsPower[i] = effectPower;
				alreadyExists = true;
				break;
			}
		}
		if (!alreadyExists) {//otherwise add it to the other effect
			weaponEffects.push_back(effect);
			weaponEffectsPower.push_back(effectPower);
		}
	}
}

void Weapon::removeEffectFromWeapon(std::string effect) {
	//when removing the effect copy all the data to temp vector except the effect that we wont to delete
	if (effect == "") {
		return;
	}
	std::vector<std::string> tempWeaponEffects;
	std::vector<double> tempWeaponEffectsPower;

	for (size_t i = 0; i < weaponEffects.size(); i++) {
		if (weaponEffects[i] != effect) {
			tempWeaponEffects.push_back(weaponEffects[i]);
			tempWeaponEffectsPower.push_back(weaponEffectsPower[i]);
		}
	}
	weaponEffects = tempWeaponEffects;
	weaponEffectsPower = tempWeaponEffectsPower;
}

void Weapon::changeWeaponCategory(WeaponCategory newWeaponCategory) {
	switch (weaponCategoryCheck(newWeaponCategory)){//again check if the weapon can be with that category or not
	case 0:
		std::tie(newWeaponCategory, std::ignore) = weapon;
		break;
	case 1:
		weapon = std::make_pair(newWeaponCategory, WeaponType::oneHanded);
		break;
	case 2:
		weapon = std::make_pair(newWeaponCategory, WeaponType::twoHanded);
		break;
	default:
		break;
	}
}
void Weapon::changeWeaponType(WeaponType newWeaponType) {
	switch (weaponCategoryCheck(weapon.first)) {
	case 0:
		weapon.second = newWeaponType;
		break;
	default:
		break;
	}
}

void Weapon::changeEPFromEffectInWeapon(std::string currEffect, double newEffPower) {
	if (currEffect == "" || newEffPower < 1) {
		return;
	}
	//change the power of the effect that we want
	for (size_t i = 0; i < weaponEffects.size(); i++) {
		if (weaponEffects[i] == currEffect) {
			weaponEffectsPower[i] = newEffPower;
			break;
		}
	}
}

double Weapon::weaponScore() const {
	//calculating the weapon score
	double weaponScore = 0;
	for (const auto& i : weaponEffectsPower) {
		weaponScore += i;
	}
	weaponScore += ((double)(hitDamage.first + hitDamage.second) / 2);
	if (weapon.second == WeaponType::oneHanded) {
		weaponScore *= 0.75;
	}
	else {
		weaponScore *= 1.5;
	}
	return weaponScore;
}

int Weapon::weaponCategoryCheck(WeaponCategory newWeaponCategory) {
	//if the weapon is bow or staff then it has to be 2-handed
	if (newWeaponCategory == WeaponCategory::bow || newWeaponCategory == WeaponCategory::staff) {
		return 2;
	}
	//if its dagger, then it has to be 1 handed
	else if (newWeaponCategory == WeaponCategory::dagger) {
		return 1;
	}
	//if its none, it can be both
	else {
		return 0;
	}
}

std::string Weapon::print()const {//print
	std::stringstream ss;
	ss << "Name: " << weaponName << "  Weapon category: " << (int)weapon.first << "  Weapon type: " << (int)weapon.second <<
		"  hit-damage: " << hitDamage.first << '-' << hitDamage.second << "\nEnchants: \n";
	for (size_t i = 0; i < weaponEffects.size(); i++) {
		ss << weaponEffects[i] << " " << weaponEffectsPower[i] << "\n";
	}
	ss << "=====================\n";
	ss << "WeaponScore: " << weaponScore() << std::endl;
	return ss.str();
}
