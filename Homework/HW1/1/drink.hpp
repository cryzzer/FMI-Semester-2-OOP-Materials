#pragma once

class Drink {
public:
    Drink();
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);
    ~Drink();

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;
    
    void set_name(const char* new_name);


    void printDrink();
    
    // Add whatever you deem needed here
private:
    // Add whatever you deem needed here
    char* name = nullptr;
    double quantity = 0;
    int calories = 0;
    double price = 0;
};
