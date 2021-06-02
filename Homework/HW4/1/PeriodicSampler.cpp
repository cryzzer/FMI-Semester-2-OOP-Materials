#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period)
    : Subscriber(id), period(period) {}

void PeriodicSampler::signal(Message message) {
  if (counter % period == 0) {
    messages.push_back(message);
  }
  counter++;
}

int PeriodicSampler::read() const {
  if (messages.empty()) {
    return 0;
  }
  return messages[messages.size() - 1].data;
}
