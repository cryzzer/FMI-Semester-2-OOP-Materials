#pragma once

template <typename T>

class Optional{
public:
    Optional();//default constructor
    Optional(const T& value);// //constructor with parameter

    bool is_none() const;//function that returns if the object is empty or not
    T get_value() const; // getting the value of T
private:
    T object;
    bool objectIsEmpty;//flag that signals if a parameter has been entered or not
};

template <class T>
Optional<T>::Optional() {//if a default constructor is called, the object is empty and we call the default constructor for `T`
    objectIsEmpty = true;
    object = T();
}

template <class T>
Optional<T>::Optional(const T& value) {
    //if we call constructor with parameter, we assign the value of the `value` to th `object` and then the ojbect is not empty
    object = value;
    objectIsEmpty = false;
}

template <class T>
bool Optional<T>::is_none() const {
    //this func is used like gettter for `objectIsEmpty` boolean
    if (objectIsEmpty) {
        return true;
    }
    else {
		return false;
    }
}

template <class T>
T Optional<T>::get_value() const {//getting the value of the object
    return object;
}
