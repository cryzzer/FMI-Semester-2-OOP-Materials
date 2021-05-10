#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial,
                                           unsigned int step)
    : LimitedCounter(max, initial, step),
      TwowayCounter(initial, step),
      Counter(initial, step),
      minCounter(min) {
}

void LimitedTwowayCounter::decrement(){
  if ((counter - step) >= minCounter) {
    counter -= step;
  }
}
int LimitedTwowayCounter::getMin() const{
  return minCounter;
}