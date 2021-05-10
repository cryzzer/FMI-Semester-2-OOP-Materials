#pragma once

#include "Counter.hpp"

class LimitedCounter : virtual public Counter {
 public:
  LimitedCounter(int max = 100, int initial = 0, unsigned int step = 1);
  void increment() override;//overriding increment
  int getMax() const;
  
 protected:
  int maxCounter;
};