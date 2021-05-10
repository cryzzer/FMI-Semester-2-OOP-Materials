#include "Counter.hpp"

Counter::Counter(int initial, unsigned int step) : counter(initial) , step(step){
}

void Counter::increment(){
  // increasing the value of counter
  counter += step;
}

int Counter::getTotal() const{
  return counter;
}

unsigned int Counter::getStep() const{
  return step;
}
