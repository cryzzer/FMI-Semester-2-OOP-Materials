#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period)
    : Subscriber(id), period(period) {}

// allow for message to be signaled after a certain period, when counter %
// period == 0, send this message
void PeriodicSampler::signal(Message message) {
  if (counter % period == 0) {
    messages.push_back(message);
  }
  counter++;
}

// return the last sent message
int PeriodicSampler::read() const {
  if (messages.empty()) {
    return 0;
  }
  return messages[messages.size() - 1].data;
}

// return the clone of this object
Subscriber* PeriodicSampler::clone() {
  return new PeriodicSampler(*this);
}
