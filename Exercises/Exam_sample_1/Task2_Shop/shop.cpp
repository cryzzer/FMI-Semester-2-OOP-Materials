#include "shop.hpp"
#include <iostream>

Shop::~Shop() {
  for (auto items : products) {
    delete items;
  }
}

Shop::Shop(const Shop& rhs) {
  for (auto items : rhs.products) {
    products.push_back(items->clone());
  }
}
Shop& Shop::operator=(const Shop& rhs) {
  if (this != &rhs) {
    for (auto items : products) {
      delete items;
    }

    products.clear();

    for (auto items : rhs.products) {
      products.push_back(items->clone());
    }
  }
   return *this;
}

void Shop::addNewProduct(StoreItem* product) {
  products.push_back(product);
}

void Shop::removeProduct(size_t index) {
  if (index >= 0 && index < products.size()) {
    delete products[index];
    products.erase(products.begin() + index);
  }
}
void Shop::changeProductPrice(size_t index, double newPrice){
  if (index >= 0 && index < products.size()) {
    Fruit* fruitPtr = dynamic_cast<Fruit*>(products[index]);
    if (fruitPtr) {
      fruitPtr->setPrice(newPrice);
    }

    Vegetable* vegetablePtr = dynamic_cast<Vegetable*>(products[index]);
    if (vegetablePtr) {
      vegetablePtr->setPrice(newPrice);
    }
  }
}

void Shop::changeProductName(size_t index, std::string newName) {
  if (index >= 0 && index < products.size()) {
    Fruit* fruitPtr = dynamic_cast<Fruit*>(products[index]);
    if (fruitPtr) {
      fruitPtr->setName(newName);
    }

    Vegetable* vegetablePtr = dynamic_cast<Vegetable*>(products[index]);
    if (vegetablePtr) {
      vegetablePtr->setName(newName);
    }
  }
}

void Shop::printProducts() const{
  for (auto item : products) {
    item->print();
    std::cout << std::endl;
  }
}

Fruit* Shop::mostCalories(){
  Fruit* returnPtr = nullptr;

  for (size_t i = 0; i < products.size(); i++) {
    Fruit* fruitPtr = dynamic_cast<Fruit*>(products[i]);
    if (fruitPtr) {
      if (returnPtr == nullptr) {
        returnPtr = fruitPtr;
        continue;
      }

      if (*fruitPtr > *returnPtr) {
        returnPtr = fruitPtr;
      }
    }
  }
  return returnPtr;
}
