#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber* sub) {
  subPtrs.push_back(sub);
}

void SimplePublisher::unsubscribe(Subscriber* sub) {
  for (size_t i = 0; i < subPtrs.size(); i++) {
    if (subPtrs[i] == sub) {
      subPtrs.erase(subPtrs.begin() + i);
      break;
    }
  }
}

void SimplePublisher::signal(Message message) {
  for (auto x : subPtrs) {
    x->signal(message);
  }
}