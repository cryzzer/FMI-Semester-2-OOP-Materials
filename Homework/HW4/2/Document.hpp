#pragma once

#include <vector>

#include "Object.hpp"

class Document : public Object {
 public:
  Document(const std::string& name = "", const std::string& location = "",
           const std::string& extension = "");

  void write_line(const std::string& line);

  std::string read_line();
  std::string read_line(const unsigned line);

  bool operator==(const Comparable* rhs) const override;
  bool operator!=(const Comparable* rhs) const override;

  std::string to_string() const override;
  void from_string(const std::string& str) override;

  std::string debug_print() const override;

  Object* clone() const override;

  std::string getLine(const unsigned int& index) const;
  void changeLine(const unsigned int& index,const std::string& newStr);

 private:
  std::vector<std::string> lines;

  unsigned int currentLine;
};
