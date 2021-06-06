#include "KeyValueDatabase.hpp"

#include <sstream>
#include <stdexcept>

KeyValueDatabase::KeyValueDatabase(const std::string& name,
                                   const std::string& location,
                                   const std::string& extension)
    : Object(name, location, extension) {}

// add a key and value to the database
void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry) {
  for (auto element : keyValue) {
    if (element.first == entry.first) {
      throw std::invalid_argument("Key already exists!");
    }
  }
  keyValue.push_back(entry);
}

// try to get the value from this database if key is equal to the key with value
// behind
int KeyValueDatabase::get_value(const std::string& key) const {
  for (auto element : keyValue) {
    if (element.first == key) {
      return element.second;
    }
  }
  throw std::invalid_argument("This key does not exists in the Database!");
}

// Try to cast 'rhs' to KeyValueDatabase pointer and if successful compare the
// two Databases if they are equal. To be equal they have to have equal amount
// of combinations(key + value), and each combination has to be the same as the
// other one at a certain index.
bool KeyValueDatabase::operator==(const Comparable* rhs) const {
  auto otherKeyValuePtr = dynamic_cast<const KeyValueDatabase*>(rhs);

  if (otherKeyValuePtr &&
      (this->keyValue.size() == otherKeyValuePtr->getSize())) {
    for (size_t i = 0; i < keyValue.size(); i++) {
      if (keyValue[i] != otherKeyValuePtr->getPair(i)) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

// call operator== and if it returns that they are equal, return false
bool KeyValueDatabase::operator!=(const Comparable* rhs) const {
  if (operator==(rhs)) {
    return false;
  } else {
    return true;
  }
}

// return all data in the Database to string
std::string KeyValueDatabase::to_string() const {
  std::stringstream ss;
  ss << name << '\n' << location << '\n' << extension << '\n';

  for (auto element : keyValue) {
    ss << element.first << ":" << element.second << "\n";
  }

  return ss.str();
}

// get the information from string and rewrite all data using this info
void KeyValueDatabase::from_string(const std::string& str) {
  std::istringstream iss(str);

  std::getline(iss, name);
  std::getline(iss, location);
  std::getline(iss, extension);

  keyValue.clear();

  std::string tempStr;
  std::string tempValue;

  while (std::getline(iss, tempStr, ':')) {
    std::getline(iss, tempValue);
    int intTempValue = std::stoi(tempValue);

    keyValue.push_back(std::pair<std::string, int>(tempStr, intTempValue));
  }
}

// print all combinations(key + value)
std::string KeyValueDatabase::debug_print() const {
  std::stringstream ss;
  for (auto element : keyValue) {
    ss << "{" << element.first << ":" << element.second << "}"
       << "\n";
  }
  return ss.str();
}

// return a clone of this object
Object* KeyValueDatabase::clone() const {
  return new KeyValueDatabase(*this);
}

// get the combination(key + value) at a certain index
std::pair<std::string, int> KeyValueDatabase::getPair(
    const unsigned int& index) const {
  if (index >= keyValue.size()) {
    throw std::out_of_range("Index is out of range!");
  }
  return keyValue[index];
}

// get the size of the vector
unsigned int KeyValueDatabase::getSize() const {
  return keyValue.size();
}