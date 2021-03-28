#include "Error.hpp"
#include "HelpfulFuncs.hpp"

Error::Error():errortype(ErrorType::None), message(nullptr){//default constructor
}
Error::~Error() {//destructor
	delete[] message;
}
Error::Error(const Error& newError) {//copy constructor
	copy(newError);
}

Error& Error::operator=(const Error& rhs) {//operator=
	if (this != &rhs) {
		copy(rhs);
	}
	return *this;
}

//function that returns if the Error has message
bool Error::hasMessage() const {
	if (message == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

//returning message if such, oshtewise return nullptr
const char* Error::getMessage() const {
	if (hasMessage()) {
		return message;
	}
	else {
		return nullptr;
	}
}

//getting type
ErrorType Error::getType() const {
	return errortype;
}

/// Create a new error of type None with no message
Error Error::newNone() {
	Error err;
	err.errortype = ErrorType::None;
	err.message = nullptr;
	return err;
}

/// Create a new error of type BuildFailed with a message
Error Error::newBuildFailed(const char* message) {
	Error err;
	err.errortype = ErrorType::BuildFailed;
	delete[] err.message;
	int size = myStrlen(message);
	err.message = new char[size + 1];
	myStrcpy(err.message, message, size);

	return err;
}

/// Create a new error of type Warning with a message
Error Error::newWarning(const char* message) {
	Error err;
	err.errortype = ErrorType::Warning;
	delete[] err.message;
	int size = myStrlen(message);
	err.message = new char[size + 1];
	myStrcpy(err.message, message, size);

	return err;
}

/// Create a new error of type FailedAssertion with a message
Error Error::newFailedAssertion(const char* message) {
	Error err;
	err.errortype = ErrorType::FailedAssertion;
	delete[] err.message;
	int size = myStrlen(message);
	err.message = new char[size + 1];
	myStrcpy(err.message, message, size);

	return err;
}

void Error::copy(const Error& newError) {
	this->errortype = newError.errortype;
	delete[] message;

	//if the message is nullptr there is no need to copy it to 'this->message'
	if (newError.message != nullptr) {
		int size = myStrlen(newError.message);
		message = new char[size + 1];
		myStrcpy(message, newError.message, size);
	}
	else {
		message = nullptr;
	}
}