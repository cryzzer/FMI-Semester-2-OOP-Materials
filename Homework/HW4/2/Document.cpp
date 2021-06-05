#include "Document.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

Document::Document(const std::string& name, const std::string& location,
                   const std::string& extension)
    : Object(name, location, extension), currentLine(1) {}

void Document::write_line(const std::string& line) {
  lines.push_back(line);
  //
}

std::string Document::read_line() {
  if (lines.empty()) {
    throw std::out_of_range("No data entered!");
  }
  if (lines.size() < currentLine) {
    currentLine = 1;
    throw std::out_of_range("End of document reached!");
  }
  currentLine++;

  return lines[currentLine - 2];
}

std::string Document::read_line(const unsigned line) {
  if (lines.empty()) {
    throw std::out_of_range("No data entered!");
  }
  if (lines.size() < line) {
    throw std::out_of_range("End of document reached!");
  }

  currentLine = line;

  currentLine++;

  return lines[currentLine - 2];
}

bool Document::operator==(const Comparable* rhs) const {
  auto docPtr = dynamic_cast<const Document*>(rhs);

  if (docPtr && (this->lines.size() == docPtr->lines.size())) {
    for (size_t i = 0; i < lines.size(); i++) {
      if (lines[i] != docPtr->lines[i]) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

bool Document::operator!=(const Comparable* rhs) const {
  if (operator==(rhs)) {
    return false;
  } else {
    return true;
  }
}

std::string Document::to_string() const {
  std::stringstream ss;
  ss << name << '\n' << location << '\n' << extension << '\n';

  for (auto line : lines) {
    ss << line << '\n';
  }

  return ss.str();
}
void Document::from_string(const std::string& str) {
  std::istringstream iss(str);

  std::getline(iss, name);
  std::getline(iss, location);
  std::getline(iss, extension);

  lines.clear();

  std::string tempStr;
  while (std::getline(iss, tempStr)) {
    lines.push_back(tempStr);
  }

  currentLine = 1;
}

std::string Document::debug_print() const {
  std::stringstream ss;
  for (size_t i = 0; i < lines.size(); i++) {
    ss << i + 1 << ":" << lines[i] << '\n';
  }

  return ss.str();
}

Object* Document::clone() const {
  return new Document(*this);
  //
}
