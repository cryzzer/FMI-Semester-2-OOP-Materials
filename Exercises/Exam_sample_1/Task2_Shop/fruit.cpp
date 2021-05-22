#include "fruit.hpp"

#include <iostream>

Fruit::Fruit(int calories, double price, std::string fruitName,
             std::string fruitColor)
    : StoreItem(ProductType::FRUIT, calories, price),
      name(fruitName),
      color(fruitColor) {}

std::string Fruit::getName() {
  return name;
}
void Fruit::setName(std::string newName) {
  name = newName;
}
void Fruit::setColor(std::string newColor) {
  color = newColor;
}
bool Fruit::operator>(const Fruit& rhs) const {
  return this->getCalories() > rhs.getCalories();
}
void Fruit::print() {
  std::cout << "Product type: " << getTypeOfProduct() << std::endl;
  std::cout << "Product name: " << name << std::endl;
  std::cout << "Product color: " << color << std::endl;
  std::cout << "Product calories: " << getCalories() << std::endl;
  std::cout << "Product price: " << getPrice() << std::endl;
}

StoreItem* Fruit::clone(){
  return new Fruit(*this);
}