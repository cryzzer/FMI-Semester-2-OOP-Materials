#include "Document.hpp"

#include <sstream>
#include <stdexcept>

Document::Document(const std::string& name, const std::string& location,
                   const std::string& extension)
    : Object(name, location, extension), currentLine(1) {}

// add a new line to the document
void Document::write_line(const std::string& line) {
  lines.push_back(line);
}

// read the line, where currentLine points (lines start from 1, not 0), that's
// why currentLine adds one to itself, because its increasing the counter of the
// line that has to be read next time, and after that do 'currentLine - 2' to
// get the index of the line that we want to read
std::string Document::read_line() {
  if (lines.empty()) {
    throw std::out_of_range("No data entered!");
  }
  if (lines.size() < currentLine) {
    throw std::out_of_range("End of document reached!");
  }
  currentLine++;

  return lines[currentLine - 2];
}

// same logic goes here, as the read_line() without index
std::string Document::read_line(const unsigned line) {
  if (lines.empty()) {
    throw std::out_of_range("No data entered!");
  }
  if (lines.size() < line || line <= 0) {
    throw std::out_of_range("End of document reached!");
  }

  currentLine = line;

  currentLine++;

  return lines[currentLine - 2];
}

// Try to cast 'rhs' to Document pointer and if successful compare the two
// Documents if they are equal. To be equal they have to have equal amount of
// lines, and each line to be the same as the other one at a certain row.
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

// call operator== and if it returns that they are equal, return false
bool Document::operator!=(const Comparable* rhs) const {
  if (operator==(rhs)) {
    return false;
  } else {
    return true;
  }
}

// return all information in the Document as a string
std::string Document::to_string() const {
  std::stringstream ss;
  ss << name << '\n' << location << '\n' << extension << '\n';

  for (auto line : lines) {
    ss << line << '\n';
  }

  return ss.str();
}

// take information from string and rewrite all data in Document using the info
// from string
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

// print the info from vector
std::string Document::debug_print() const {
  std::stringstream ss;
  for (size_t i = 0; i < lines.size(); i++) {
    ss << "Line " << i + 1 << ":" << lines[i] << '\n';
  }

  return ss.str();
}

// return a clone of this object
Object* Document::clone() const {
  return new Document(*this);
  //
}

// get a certain line from Document
std::string Document::getLine(const unsigned int& index) const {
  if (index < lines.size()) {
    return lines[index];
  }
  return "";
}

// change a certain line from Document
void Document::changeLine(const unsigned int& index,
                          const std::string& newStr) {
  if (index < lines.size()) {
    lines[index] = newStr;
  }
}