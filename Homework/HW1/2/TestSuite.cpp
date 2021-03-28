#include <string>
#include <vector>

#include "TestCase.hpp"
#include "TestSuite.hpp"


TestSuite::TestSuite(std::string name) {//constructor
	setName(name);
}

void TestSuite::add(const TestCase& newTestCase) {//adding new TestCase to the 'tests'
	tests.push_back(newTestCase);
}

//checking for each TestCase in the vector 'tests' with the function 'isPassing()' 
//and this function returns true/false, in that case if it returns true(that the TestCase
//is passing) we add this case in the new vector 'temp' and at the end we return it
std::vector<TestCase> TestSuite::filterPassing() const {
	std::vector<TestCase> temp;
	for (int i = 0; i < tests.size(); i++) {
		if (tests[i].isPassing()) {
			temp.push_back(tests[i]);
		}
	}
	return temp;
}

//simmilar logic to 'TestSuite::filterPassing()' but this time we check the opposite,
//if the TestCase is not passing, and similarly we add it to the vector and then return it
std::vector<TestCase> TestSuite::filterFailing() const {
	std::vector<TestCase> temp;
	for (int i = 0; i < tests.size(); i++) {
		if (!tests[i].isPassing()) {
			temp.push_back(tests[i]);
		}
	}
	return temp;
}

//again similar logic but this time we check the error type and if it maches with 
// 'ErrorType error' that we are looking for, we add it to the new vector and the return it
std::vector<TestCase> TestSuite::filterByErrorType(ErrorType error) const {
	std::vector<TestCase> temp;
	for (int i = 0; i < tests.size(); i++) {
		if (tests[i].getErrorType() == error) {
			temp.push_back(tests[i]);
		}
	}
	return temp;
}

//here we create a temporary vector, and start copying the data from our main one 'tests' to
//the temporary one, but if the 'errortype' in 'tests' matches with 'ErrorType error' we skip 
//the copying of this TestCase and continue with the next one
void TestSuite::removeByErrorType(ErrorType error) {
	std::vector<TestCase> temp;
	for (int i = 0; i < tests.size(); i++) {
		if (tests[i].getErrorType() != error) {
			temp.push_back(tests[i]);
		}
	}
	//at the end we use the "well defined" operator= and copy our temp. one to our main one  
	tests = temp;
}

//getter
std::string TestSuite::getName() const {
	return this->TSname;
}

//setter
void TestSuite::setName(const std::string& newName) {
	this->TSname = newName;
}