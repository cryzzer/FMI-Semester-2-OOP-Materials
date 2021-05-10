#include "Semaphore.hpp"

Semaphore::Semaphore(bool type) : LimitedTwowayCounter(0, 1, 0, 1){
  if (type) {
    increment();
  }
}
bool Semaphore::isAvailable() {
  return counter > 0;
}
void Semaphore::wait(){
  decrement();
}
void Semaphore::signal(){
  increment();
}