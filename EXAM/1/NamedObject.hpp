//
// 62518
//

#ifndef EXAM_NAMEDOBJECT_HPP
#define EXAM_NAMEDOBJECT_HPP

#include <iostream>
#include <cstring>

template<class T>
class NamedObject {
public:
    NamedObject();

    NamedObject(size_t id, const char *name, T &object);

    ~NamedObject();

    NamedObject(const NamedObject<T> &rhs);

    NamedObject &operator=(const NamedObject<T> &rhs);

    unsigned int getId() const;

    char *getName() const;

    T getObject() const;


private:
    size_t id;
    char *name;
    T object;

    void copy(const NamedObject<T> &rhs);

    void free();
};

template<class T>
NamedObject<T>::NamedObject(size_t id, const char *name, T &object) : id(id), object(object) {
    size_t size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);
}

template<class T>
unsigned int NamedObject<T>::getId() const {
    return id;
}

template<class T>
char *NamedObject<T>::getName() const {
    return name;
}

template<class T>
T NamedObject<T>::getObject() const {
    return object;
}

template<class T>
NamedObject<T>::~NamedObject() {
    free();
}

template<class T>
NamedObject<T>::NamedObject(const NamedObject<T> &rhs) {
    copy(rhs);
}

template<class T>
NamedObject<T> &NamedObject<T>::operator=(const NamedObject<T> &rhs) {
    if (this != &rhs) {
        free();
        copy(rhs);
    }
    return *this;
}

template<class T>
NamedObject<T>::NamedObject() : name(nullptr), id(0), object() {

}

template<class T>
void NamedObject<T>::copy(const NamedObject<T> &rhs) {
    id = rhs.id;
    object = rhs.object;

    size_t size = strlen(rhs.name);
    name = new char[size + 1];
    strcpy(name, rhs.name);
}

template<class T>
void NamedObject<T>::free() {
    delete[] name;
}


#endif //EXAM_NAMEDOBJECT_HPP
