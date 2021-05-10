#pragma once

#include "Counter.hpp"

class TwowayCounter : virtual public Counter{
 public:
  TwowayCounter(int initial = 0, unsigned int step = 1);
  virtual void decrement();
};