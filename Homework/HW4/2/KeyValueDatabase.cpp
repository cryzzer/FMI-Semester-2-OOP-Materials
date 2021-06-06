#include "KeyValueDatabase.hpp"

#include <sstream>
#include <stdexcept>

KeyValueDatabase::KeyValueDatabase(const std::string& name,
                                   const std::string& location,
                                   const std::string& extension)
    : Object(name, location, extension) {}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry) {
  for (auto element : keyValue) {
    if (element.first == entry.first) {
      throw std::invalid_argument("Key already exists!");
    }
  }
  keyValue.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const {
  for (auto element : keyValue) {
    if (element.first == key) {
      return element.second;
    }
  }
  throw std::invalid_argument("This key does not exists in the Database!");
}

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
bool KeyValueDatabase::operator!=(const Comparable* rhs) const {
  if (operator==(rhs)) {
    return false;
  } else {
    return true;
  }
}

std::string KeyValueDatabase::to_string() const {
  std::stringstream ss;
  ss << name << '\n' << location << '\n' << extension << '\n';

  for (auto element : keyValue) {
    ss << element.first << ":" << element.second << "\n";
  }

  return ss.str();
}
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

std::string KeyValueDatabase::debug_print() const {
  std::stringstream ss;
  for (auto element : keyValue) {
    ss << "{" << element.first << ":" << element.second << "}"
       << "\n";
  }
  return ss.str();
}

Object* KeyValueDatabase::clone() const {
  return new KeyValueDatabase(*this);
  //
}

std::pair<std::string, int> KeyValueDatabase::getPair(
    const unsigned int& index) const {
  if (index >= keyValue.size()) {
    throw std::out_of_range("Index is out of range!");
  }
  return keyValue[index];
}

unsigned int KeyValueDatabase::getSize() const {
  return keyValue.size();
  //
}