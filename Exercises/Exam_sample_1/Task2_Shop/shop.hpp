#pragma once
#include <vector>

#include "fruit.hpp"
#include "vegetable.hpp"

class Shop {
 public:
  Shop() = default;
  ~Shop();
  Shop(const Shop& rhs);
  Shop& operator=(const Shop& rhs);

  void addNewProduct(StoreItem* product);
  void removeProduct(size_t index);
  void changeProductPrice(size_t index, double newPrice);
  void changeProductName(size_t index, std::string newName);
  void printProducts() const;
  Fruit* mostCalories();

 private:
  std::vector<StoreItem*> products;
};