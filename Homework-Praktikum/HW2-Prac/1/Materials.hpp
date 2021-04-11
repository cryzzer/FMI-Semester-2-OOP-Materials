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

enum class MaterialsType {//4 materials
	herbs,
	ores,
	cloth,
	essence
};

class Materials{
private:
	MaterialsType matType = MaterialsType::herbs;
	int quantity = 0;
public:
	Materials();
	Materials(MaterialsType newMatType, int newQuantity);

	void addQuantity(int newQuantity);
	MaterialsType getMatType() const;
	int getQuantity() const;

	void print();
};

