#pragma once

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result {
public:
    Result();
    Result(const T &result);
    Result(const std::string &error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const Error& rhs) const;
    bool operator==(const T& rhs) const;
private:
    T option;
    std::string message;//message where we can store the error message if available
    bool noValueEntered;
};

template<class T>
Result<T>::Result() : message(""), noValueEntered(true) {
}

template<class T>
Result<T>::Result(const T& result) : message(""), option(result), noValueEntered(false) {
}

template<class T>
Result<T>::Result(const std::string& error_message) : message(error_message), noValueEntered(true) {
}

template<class T>
Optional<T> Result<T>::get_result() const {//creating an Optional<T> with `option` parameter inside, then returning this object
    Optional<T> test(option);
    return test;
}

template<class T>
Optional<Error> Result<T>::get_error() const {
    //create a new Error with error message inside, after that create Optional<Error> with parameter `err` and after that return the object
    Error err(message);
    Optional<Error> optErr(err);
    return optErr;
}

template<class T>
bool Result<T>::operator==(const T& rhs) const {//if there is no entered message and the object isn't empty return true
    if (message == "" && noValueEntered == false) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
bool Result<T>::operator==(const Error& rhs) const{
    //if there is a message and there isn't any value in the object, return true
    if (message != "" && noValueEntered == true) {
        return true;
    }
    else {
        return false;
    }
}