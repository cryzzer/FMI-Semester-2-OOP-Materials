#pragma once
#include <string>

#include "storeItem.hpp"

class Vegetable : public StoreItem {
 public:
  Vegetable(int calories = 0, double price = 0, std::string vegName = "",
            std::string vegVariety = "");

  std::string getName() const;

  void setName(std::string newName);
  void setVariety(std::string newVariety);

  bool operator==(const Vegetable& rhs) const;
  void print();
  StoreItem* clone() override;
  

 private:
  std::string name;
  std::string variety;
};