#include <iostream>

#include "TwowayCounter.hpp"
#include "LimitedCounter.hpp"
#include "LimitedTwowayCounter.hpp"
#include "Semaphore.hpp"

int main() {
  Counter c1;
  c1.increment();
  std::cout << c1.getTotal() << std::endl;
  std::cout << "=========================\n";

  Counter c2(6);
  c2.increment();
  std::cout << c2.getTotal() << std::endl;
  std::cout << "=========================\n";


  Counter c3(9,2);
  c3.increment();
  std::cout << c3.getTotal() << std::endl;
  std::cout << "=========================\n";

  TwowayCounter c4;
  c4.increment();
  std::cout << c4.getTotal() << std::endl;
  c4.decrement();
  std::cout << c4.getTotal() << std::endl;
  std::cout << "=========================\n";

  TwowayCounter c5(69,420);
  std::cout << c5.getStep() << std::endl;
  std::cout << c5.getTotal() << std::endl;
  std::cout << "=========================\n";

  LimitedCounter c6(3);
  c6.increment();
  c6.increment();
  c6.increment();
  c6.increment();
  c6.increment();
  c6.increment();
  c6.increment();
  std::cout << c6.getTotal() << std::endl;
  std::cout << "=========================\n";

  LimitedTwowayCounter c7(0,5,1);
  std::cout << c7.getMin() << "    " << c7.getMax() << "        " << c7.getTotal() << "             " << c7.getStep() << std::endl;
  std::cout << c7.getTotal() << std::endl;
  c7.decrement();
  std::cout << c7.getTotal() << std::endl;
  c7.decrement();
  c7.decrement();
  std::cout << c7.getTotal() << std::endl;
  c7.increment();
  c7.increment();
  c7.increment();
  c7.increment();
  c7.increment();
  c7.increment();
  c7.increment();
  c7.increment();
  std::cout << c7.getTotal() << std::endl;
  std::cout << "=========================\n";


  Semaphore c8;
  std::cout << c8.getMin() << "    " << c8.getMax() << "        " << c8.getTotal() << "             " << c8.getStep() << std::endl;
  std::cout << "=========================\n";

  Semaphore c9(true);
  std::cout << c9.getMin() << "    " << c9.getMax() << "        " << c9.getTotal() << "             " << c9.getStep() << std::endl;
  std::cout << std::boolalpha << c9.isAvailable() << std::endl;
  c9.wait();
  std::cout << c9.getTotal() << std::endl;
  c9.wait();
  c9.wait();
  std::cout << c9.getTotal() << std::endl;
  c9.signal();
  std::cout << c9.getTotal() << std::endl;
  c9.signal();
  c9.signal();
  c9.signal();
  std::cout << c9.getTotal() << std::endl;
  std::cout << "=========================\n";

}