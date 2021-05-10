#pragma once

class Counter {
 public:
  Counter(int initial = 0, unsigned int step = 1);

  virtual void increment();//virtual function because we override it when inheriting
  int getTotal() const;
  unsigned int getStep() const;

 protected:
  int counter;
  int step;
};