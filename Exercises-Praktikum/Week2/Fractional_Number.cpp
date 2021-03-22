#include "Fractional_Number.hpp"
#include <iostream>

using namespace std;

void my_abs(int & num) {
	if (num < 0) {
		num = -num;
	}
}

void shorteningFracNum(int& numen, int& denomen) {
	bool oneIsNegative = false;
	if (numen < 0 && denomen < 0) {
		my_abs(numen);
		my_abs(denomen);
	}
	else if (denomen < 0) {
		oneIsNegative = true;
		my_abs(denomen);
	}
	else if (numen < 0) {
		oneIsNegative = true;
		my_abs(numen);
	}

	int lowerNum = 0;

	if (numen >= denomen) {
		lowerNum = denomen;
	}
	else {
		lowerNum = numen;
	}

	for (int i = 2;i <= lowerNum; i++) {
		if (numen % i == 0 && denomen % i == 0) {
			numen = numen / i;
			denomen = denomen / i;
			i--;
		}
	}
	
	if (oneIsNegative) {
		numen = -numen;
	}
}

void Fractional_Number::addTwoFracNums(Fractional_Number secondFracNum){
	//cout << numenator << ' ' << denomenator << ' ' << secondFracNum.numenator << ' ' << secondFracNum.denomenator << endl;

	numenator = (numenator * secondFracNum.denomenator) + (secondFracNum.numenator * denomenator);
	denomenator = denomenator * secondFracNum.denomenator;
	//std::cout << "numenator is : " << numenator << "   denomenator is : " << denomenator << std::endl;

	if (numenator == 0) {
		return;
	}
	else if (denomenator == 0) {
		std::cout << "Impossible fractial number" << std::endl;
		numenator = 0;
	}

	shorteningFracNum(numenator, denomenator);
}

void Fractional_Number::multiplyTwoFracNums(Fractional_Number secondFracNum) {
	denomenator = denomenator * secondFracNum.denomenator;
	numenator = numenator * secondFracNum.numenator;

	if (numenator == 0) {
		return;
	}
	else if (denomenator == 0) {
		std::cout << "Impossible fractial number" << std::endl;
		numenator = 0;
	}

	shorteningFracNum(numenator, denomenator);
}

void Fractional_Number::printFracNum() {

	std::cout << numenator << " / " << denomenator << std::endl;
}
