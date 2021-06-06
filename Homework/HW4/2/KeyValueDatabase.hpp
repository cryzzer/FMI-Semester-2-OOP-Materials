#pragma once

#include <vector>

#include "Object.hpp"

class KeyValueDatabase : public Object {
 public:
  KeyValueDatabase(const std::string& name = "",
                   const std::string& location = "",
                   const std::string& extension = "");

  void add_entry(const std::pair<std::string, int>& entry);
  int get_value(const std::string& key) const;

  bool operator==(const Comparable* rhs) const override;
  bool operator!=(const Comparable* rhs) const override;

  std::string to_string() const override;
  void from_string(const std::string& str) override;

  std::string debug_print() const override;

  Object* clone() const override;

  std::pair<std::string, int> getPair(const unsigned int& index) const;
  unsigned int getSize() const;

 private:
  std::vector<std::pair<std::string, int>> keyValue;
};
