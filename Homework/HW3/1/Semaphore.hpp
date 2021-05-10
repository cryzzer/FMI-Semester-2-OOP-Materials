#pragma once

#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter {
 public:
  Semaphore(bool type = false);
  bool isAvailable();
  void wait();
  void signal();
};