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

#include "Armor.hpp"
#include <iostream>
#include <sstream>

Armor::Armor() : armorName(""), typeOfArmor(ArmorType::cloth), defence(0) {
}

Armor::Armor(std::string newArmorName, ArmorType newType, int newDef) : armorName(newArmorName), typeOfArmor(newType), defence(newDef) {
}

std::string Armor::getArmorName() const {
	return armorName;
}
ArmorType Armor::getArmorType() const {
	return typeOfArmor;
}
int Armor::getDefence() const {
	return defence;
}
std::vector<std::string> Armor::getArmorEffects() const {
	return armorEffects;
}
std::vector<double> Armor::getArmorEffectsPower() const {
	return armorEffectsPower;
}

void Armor::addNewEffectToArmor(std::string effect, double effectPower) {
	if (effect != "" && effectPower > 0) {
		bool alreadyExists = false;
		for (size_t i = 0; i < armorEffects.size(); i++) {//if effect already exists, just change his power
			if (armorEffects[i] == effect) {
				armorEffectsPower[i] = effectPower;
				alreadyExists = true;
				break;
			}
		}
		if (!alreadyExists) {//otherwise add it to the other effect
			armorEffects.push_back(effect);
			armorEffectsPower.push_back(effectPower);
		}
	}
}
double Armor::gearScore() const {//calculating the gearscore
	double gearScore = 0;
	for (const auto& i : armorEffectsPower) {
		gearScore += i;
	}
	return gearScore;
}

std::string Armor::print() const {//print func
	std::stringstream ss;
	ss << "Name: " << armorName << "  Armor type: " << (int)typeOfArmor << "  defence: " << defence << "\nEnchants: \n";
	for (size_t i = 0; i < armorEffects.size(); i++) {
		ss << armorEffects[i] << " " << armorEffectsPower[i] << "\n";
	}
	ss << "=====================\n";
	ss << "GearScore: " << gearScore() << std::endl;
	return ss.str();
}
