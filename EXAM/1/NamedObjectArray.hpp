//
// 62518
//

#ifndef EXAM_NAMEDOBJECTARRAY_HPP
#define EXAM_NAMEDOBJECTARRAY_HPP

#include "NamedObject.hpp"
#include <stdexcept>

template<class T>
class NamedObjectArray {
public:
    NamedObjectArray() = default;
    ~NamedObjectArray();
    NamedObjectArray(const NamedObjectArray<T>& rhs);
    NamedObjectArray& operator=(const NamedObjectArray<T>& rhs);
    void addObject(const NamedObject<T>& obj);

    int getSize() const;

    NamedObject<T>& operator[](size_t index);
private:
    NamedObject<T>* namedObjects;
    int size = 0;

    void copy(const NamedObjectArray<T>& rhs);
    void free();
};

template<class T>
NamedObjectArray<T>::~NamedObjectArray() {
    free();
}

template<class T>
NamedObjectArray<T>::NamedObjectArray(const NamedObjectArray<T> &rhs) {
    copy(rhs);
}

template<class T>
NamedObjectArray<T> &NamedObjectArray<T>::operator=(const NamedObjectArray<T> &rhs) {
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

template<class T>
void NamedObjectArray<T>::addObject(const NamedObject<T> &obj) {
    NamedObject<T>* temp = new NamedObject<T>[size+1];
    if(size>0){
        for (int i = 0; i < size; ++i) {
            temp[i] = namedObjects[i];
        }
        temp[size] = obj;

        size++;

        delete[] namedObjects;

        namedObjects = temp;
    }
    else{
        namedObjects = new NamedObject<T>[1];
        namedObjects[0] = obj;
        size++;
    }

}

template<class T>
int NamedObjectArray<T>::getSize() const {
    return size;
}

template<class T>
NamedObject<T> &NamedObjectArray<T>::operator[](size_t index) {
    if(index < size){
        return namedObjects[index];
    }
    else{
        throw std::out_of_range("Out of range!");
    }
}

template<class T>
void NamedObjectArray<T>::copy(const NamedObjectArray<T> &rhs) {
    size = rhs.size;
    namedObjects = new NamedObjectArray<T>[size];
    for (int i = 0; i < size; ++i) {
        namedObjects[i] = rhs.namedObjects[i];
    }
}

template<class T>
void NamedObjectArray<T>::free() {
    delete[] namedObjects;
    size = 0;
}
#endif //EXAM_NAMEDOBJECTARRAY_HPP
