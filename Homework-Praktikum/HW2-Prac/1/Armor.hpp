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
#include <string>
#include <vector>

enum class ArmorType {
	cloth,
	leather,
	mail
};

class Armor{
private:
	std::string armorName = "";
	ArmorType typeOfArmor = ArmorType::cloth;
	int defence = 0;
	std::vector<std::string> armorEffects;
	std::vector<double> armorEffectsPower;
public:
	Armor();
	Armor(std::string newArmorName,ArmorType newType, int newDef);

	std::string getArmorName() const;
	ArmorType getArmorType() const;
	int getDefence() const;
	std::vector<std::string> getArmorEffects() const;//using two vectors, one for effect, one for effect power
	std::vector<double> getArmorEffectsPower() const;

	void addNewEffectToArmor(std::string effect, double effectPower);
	double gearScore() const;

	std::string print() const;
};

