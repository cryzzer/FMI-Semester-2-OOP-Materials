#pragma once

enum ProductType { 
    FRUIT,
    VEGETABLE 
};

class StoreItem {
 public:
  StoreItem(ProductType typeOfProduct = ProductType::FRUIT, int calories = 0, double price = 0);
  virtual ~StoreItem() = default;

  virtual ProductType getTypeOfProduct() const;
  virtual int getCalories() const;
  virtual double getPrice() const;

  virtual void setTypeOfProduct(ProductType newTypeOfProduct);
  virtual void setCalories(int newCalories);
  virtual void setPrice(double newPrice);

  virtual void print() = 0;
  virtual StoreItem* clone() = 0;
 private:
  ProductType typeOfProduct;
  int calories;
  double price;

};