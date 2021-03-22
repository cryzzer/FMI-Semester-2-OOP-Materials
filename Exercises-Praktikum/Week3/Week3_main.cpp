#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "UserInfo.hpp"
#include "Car.hpp"
#include "Parking.hpp"

using namespace std;

int main()
{
	/*UserInfo user;
	cout << user.getUsername() << ' ' << user.getPass() << endl;

	UserInfo user2("pepoooo");
	cout << user2.getUsername() << ' ' << user2.getPass() << endl;

	UserInfo user3(user2);
	cout << user3.getUsername() << ' ' << user3.getPass() << endl;*/

    Car car1 = Car("Model 1", "Number 1", "Color 1");

    Car car2 = Car("Model 2", "Number 2", "Color 2");

    Car car3 = Car("Model 3", "Number 3", "Color 3");

    Car car4 = Car("Model 4", "Number 4", "Color 4");

    Car car5 = Car("Model 5", "Number 5", "Color 5");

    Car* carArray = new Car[3];
    carArray[0] = car1;
    carArray[1] = car2;
    carArray[2] = car3;

    Parking parking("My Parking", carArray, 3);

    /*parking.PrintAllCars();

    cout << "------------------------" << endl;

    parking.addCar(car4);

    parking.PrintAllCars();

    cout << "------------------------" << endl;

    parking.removeCar(1);

    parking.PrintAllCars();

    cout << "------------------------" << endl;

    parking.addCarAtIndex(3, car5);

    parking.PrintAllCars();

    cout << "------------------------" << endl;

    cout << parking.getModel(car3.getNumber()) << endl;*/


}
