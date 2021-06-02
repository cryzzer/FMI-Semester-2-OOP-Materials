#include "Averager.hpp"

Averager::Averager(std::string id) : Subscriber(id) {}

int Averager::read() const {
  if (messages.empty()) {
    return 0;
  }

  int returnValue = 0;

  for (auto x : messages) {
    returnValue += x.data;
  }

  return returnValue / messages.size();
}