#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize)
    : Subscriber(id) {}

int MovingAverager::read() const {
  if (messages.empty()) {
    return 0;
  }

  int returnValue = 0;

  if (windowSize > messages.size()) {
    for (auto x : messages) {
      returnValue += x.data;
    }

    return returnValue / messages.size();
  } else {
    size_t counter = 0;

    for (size_t i = messages.size() - 1; i <= 0; i--) {
      if (counter == windowSize) {
        break;
      }

      returnValue += messages[i].data;
      counter++;
    }

    return returnValue / windowSize;
  }
}