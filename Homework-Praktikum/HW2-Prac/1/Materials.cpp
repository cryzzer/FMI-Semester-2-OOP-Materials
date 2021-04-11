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

#include "Materials.hpp"
#include <iostream>

Materials::Materials() : matType(MaterialsType::herbs), quantity(0) {
}
Materials::Materials(MaterialsType newMatType, int newQuantity) : matType(newMatType), quantity(newQuantity) {
}

void Materials::addQuantity(int newQuantity) {
	quantity += newQuantity;
}

MaterialsType Materials::getMatType() const {
	return matType;
}
int Materials::getQuantity() const {
	return quantity;
}

void Materials::print() {
	std::cout << "material is: " << (int)matType << '\n' << "quantity is: " << quantity << '\n';
}
