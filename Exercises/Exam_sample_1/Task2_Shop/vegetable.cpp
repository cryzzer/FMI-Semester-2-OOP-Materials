#include "vegetable.hpp"

#include <iostream>

Vegetable::Vegetable(int calories, double price, std::string vegName,
                     std::string vegVariety)
    : StoreItem(ProductType::VEGETABLE, calories, price),
      name(vegName),
      variety(vegVariety) {}

std::string Vegetable::getName() const {
  return name;
}
void Vegetable::setName(std::string newName) {
  name = newName;
}
void Vegetable::setVariety(std::string newVariety) {
  variety = newVariety;
}

bool Vegetable::operator==(const Vegetable& rhs) const {
  return variety == rhs.variety;
}

void Vegetable::print() {
  std::cout << "Product type: " << getTypeOfProduct() << std::endl;
  std::cout << "Product name: " << name << std::endl;
  std::cout << "Product variety: " << variety << std::endl;
  std::cout << "Product calories: " << getCalories() << std::endl;
  std::cout << "Product price: " << getPrice() << std::endl;
}

StoreItem* Vegetable::clone() {
  return new Vegetable(*this);
}
