#include <iostream>

#include "fruit.hpp"
#include "storeItem.hpp"
#include "vegetable.hpp"
#include "shop.hpp"

int main() {
  Fruit t1;
  t1.setName("Melon");
  t1.setColor("Yellow");
  t1.setCalories(30);
  t1.setPrice(1.50);
  t1.print();

  Fruit fr1(50,200,"banana", "yellow");
  fr1.print();
  if (t1 > fr1) {
    std::cout << "woah";
  } 
  else {
    std::cout << "I knew it!";
  }
  std::cout << "\n\n";

  Vegetable t2;
  t2.setName("Potato");
  t2.setVariety("Fresh");
  t2.setCalories(100);
  t2.setPrice(0.80);
  t2.print();
  if (t2 == t2) {
    std::cout << "ez";
  } 
  else {
    std::cout << "not fair";
  }
  std::cout << "\n===============================\n\n";

  Shop shop;
  shop.addNewProduct(&t1);
  shop.addNewProduct(&fr1);
  shop.addNewProduct(&t2);

  shop.printProducts();
  std::cout << "\n\n";
  if(&fr1 == shop.mostCalories()){
    std::cout << "same\n";
  }
  else{
    std::cout << "not same\n";
  }
  shop.removeProduct(1);
  std::cout << "\nSECOND PRINTING\n\n";

  shop.printProducts();

  return 0;
}