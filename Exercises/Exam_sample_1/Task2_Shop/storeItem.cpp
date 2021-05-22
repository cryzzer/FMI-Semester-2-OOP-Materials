#include "storeItem.hpp"

StoreItem::StoreItem(ProductType typeOfProduct, int calories, double price)
    : typeOfProduct(typeOfProduct), calories(calories), price(price) {}

ProductType StoreItem::getTypeOfProduct() const {
  return typeOfProduct;
}
int StoreItem::getCalories() const {
  return calories;
}
double StoreItem::getPrice() const {
  return price;
}

void StoreItem::setTypeOfProduct(ProductType newTypeOfProduct) {
  typeOfProduct = newTypeOfProduct;
}
void StoreItem::setCalories(int newCalories) {
  calories = newCalories;
}
void StoreItem::setPrice(double newPrice) {
  price = newPrice;
}

