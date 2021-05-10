#include "LimitedCounter.hpp"

  LimitedCounter::LimitedCounter(int max, int initial, unsigned int step) : Counter(initial,step), maxCounter(max) {
  }
  void LimitedCounter::increment(){
    if ((counter + step) <= maxCounter) {
      // increasing the value of counter
      counter += step;
    }
  }
  int LimitedCounter::getMax() const{
    return maxCounter;
  }