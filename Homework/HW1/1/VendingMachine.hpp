#pragma once

#include "drink.hpp"

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    ~VendingMachine();
    
    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    void copy(const VendingMachine& from);
    bool checkIfDrinkExists(const Drink& to_add);
    void printVend();
    void removeDrink(const int& index);
    
    // Add whatever you deem needed here
private:
    // Add whatever you deem needed here

    Drink* drinks= nullptr;
    int drinksCount = 0;
    double income = 0;
};
