#include "Averager.hpp"

Averager::Averager(std::string id) : Subscriber(id) {}

//returns the avarage number from the container with messages
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

//returns a clone object of this object
Subscriber* Averager::clone(){
  return new Averager(*this);
}