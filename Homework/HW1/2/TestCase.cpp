#include "TestCase.hpp"
#include "Error.hpp"
#include <string>

TestCase::TestCase(const std::string& name, const Error& error) {//constructor
	this->TCname = name;
	this->error = error;
}

//getter for name
std::string TestCase::getName() const {
	return TCname;
}

//if the ErrorType is 'None' or 'Warning' the Testcase is passing, otherwise it's not
bool TestCase::isPassing() const {
	if ((error.getType() == ErrorType::None) || (error.getType() == ErrorType::Warning)) {
		return true;
	}
	else {
		return false;
	}
}

//if the ErrorType is 'None' there is no error, otherwise there is
bool TestCase::hasError() const {
	if (error.getType() == ErrorType::None) {
		return false;
	}
	else {
		return true;
	}
}

//if 'hasError' returns false the ErrorType is 'None', otherwise return the 'error.getType()'
ErrorType TestCase::getErrorType() const {
	if (!hasError()) {//if false
		return ErrorType::None;
	}
	else {
		return error.getType();
	}
}

//if there is message return it, otherwise return nullptr
std::string TestCase::getErrorMessage() const {
	if (error.getMessage() == nullptr) {
		return "";
	}
	else {
		return error.getMessage();
	}
}