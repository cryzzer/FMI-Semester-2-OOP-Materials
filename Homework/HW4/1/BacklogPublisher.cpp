#include "BacklogPublisher.hpp"

BacklogPublisher::BacklogPublisher() : SimplePublisher() {}

//when subscribing, send all previous messages to the subscribing user
void BacklogPublisher::subscribe(Subscriber* sub) {
  for (auto missedMessage : previousMessages) {
    sub->signal(missedMessage);
  }

  subPtrs.push_back(sub);
}

//send this message to all subscribers
void BacklogPublisher::signal(Message message) {
  previousMessages.push_back(message);
  for (auto x : subPtrs) {
    x->signal(message);
  }
}