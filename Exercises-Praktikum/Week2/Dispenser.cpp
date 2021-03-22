#include "Dispenser.hpp"
#include <iostream>

using namespace std;

void Dispenser::fillGlass(double glassL) {
	if (maxL >= currL) {
		if (currL > 0) {
			if (glassL <= currL) {
				currL = currL - glassL;
				cout << "You have successfully filled your glass with " << glassL << "L of water!" << endl;
			}
			else if ((currL - glassL) < 0) {
				cout << "There isn't enough water in the dispenser to fill your glass!" << endl;;
			}
		}
		else {
			cout << "You need to refill the dispenser with water!" << endl;
		}
	}
}
void Dispenser::dispenserFill(double addL) {
	if ((currL + addL) > maxL) {
		cout << "You have to fill the dispenser with less litres! The dispenser will overflow!" << endl;
	}
	else {
		currL = currL + addL;
		cout << "You have successfully refilled the dispenser!" << endl;
	}
}

