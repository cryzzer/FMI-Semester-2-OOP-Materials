#include <iostream>

#include "matrix.hpp"

int main() {
  //   Matrix<int> mat(2, 2);
  //   mat.printmatr();
  //   std::cout << "\n\n\n";
  //   mat.setAt(1, 1, 5);
  //   mat.printmatr();
  //   std::cout << "\n\n\n";
  //   mat.setAt(1, 10, 5);
  //   mat.printmatr();
  //   std::cout << "\n\n\n";
  //   std::cout << mat.getAt(1,1);
  //   std::cout << "\n\n\n";

  Matrix<int> test1(3, 2);
  test1.setAt(1, 1, 5);
  test1.setAt(1, 2, 3);
  test1.setAt(2, 1, 4);
  test1.setAt(2, 2, 1);
  test1.setAt(3, 1, 7);
  test1.setAt(3, 2, 9);
  test1.printmatr();
  std::cout << "\n\n\n";
  test1.transpose();
  test1.printmatr();
}