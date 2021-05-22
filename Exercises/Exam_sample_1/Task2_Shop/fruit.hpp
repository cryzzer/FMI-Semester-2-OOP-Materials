#pragma once
#include <string>

#include "storeItem.hpp"

class Fruit : public StoreItem {
 public:
  Fruit(int calories = 0, double price = 0, std::string fruitName = "",
        std::string fruitColor = "");

  std::string getName();

  void setName(std::string newName);
  void setColor(std::string newColor);

  bool operator>(const Fruit& rhs) const;
  void print() override;
  StoreItem* clone() override;

 private:
  std::string name;
  std::string color;
};