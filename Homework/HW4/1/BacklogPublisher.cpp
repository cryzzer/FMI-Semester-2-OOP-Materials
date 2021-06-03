#include "BacklogPublisher.hpp"

BacklogPublisher::BacklogPublisher() : SimplePublisher() {}

void BacklogPublisher::subscribe(Subscriber* sub) {
  for (auto missedMessage : previousMessages) {
    sub->signal(missedMessage);
  }

  subPtrs.push_back(sub);
}

void BacklogPublisher::signal(Message message) {
  previousMessages.push_back(message);
  for (auto x : subPtrs) {
    x->signal(message);
  }
}