#include "Repository.hpp"

// add a the clone of the subscriber that wants to subscribe
void Repository::add(Subscriber* sub) {
  subConstainer.push_back(sub->clone());
}

// empty the information about subscribers
void Repository::deleteInfo() {
  for (auto x : subConstainer) {
    delete x;
  }
  subConstainer.clear();
}

// copy the information from rhs object to 'this' object
void Repository::copyInfo(const Repository& rhs) {
  for (auto x : rhs.subConstainer) {
    subConstainer.push_back(x->clone());
  }
}

Repository::~Repository() {
  deleteInfo();
}

Repository::Repository(const Repository& rhs) {
  copyInfo(rhs);
}

Repository& Repository::operator=(const Repository& rhs) {
  if (this != &rhs) {
    deleteInfo();
    copyInfo(rhs);
  }
  return *this;
}

// get a subscriber with specific 'id'
Subscriber* Repository::get(std::string id) {
  for (auto subscriber : subConstainer) {
    if (subscriber->id == id) {
      return subscriber;
    }
  }
  return nullptr;
}
