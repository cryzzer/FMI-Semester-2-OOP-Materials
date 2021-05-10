#pragma once

#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter {
 public:
  LimitedTwowayCounter(int min = -100, int max = 100, int initial = 0, unsigned int step = 1);
  void decrement() override;
  int getMin() const;

 protected:
  int minCounter;
};