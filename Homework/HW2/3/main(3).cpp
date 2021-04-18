#include <iostream>
#include "Vector4D.hpp"

int main()
{
	Vector4D test(1,1,1,1);
	Vector4D add(0, 1, 2, 3);

	/*Vector4D zer(0, 0, 0, 0);
	if (!test) {
		std::cout << "yep";
	}
	else {
		std::cout << "nop";

	}*/

	Vector4D negative = -test;
	negative.printVec();
}

