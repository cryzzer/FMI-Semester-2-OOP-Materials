#pragma once
#include <iostream>

template <class T>
class Matrix {
 public:
  Matrix();
  Matrix(int rows, int cols);
  ~Matrix();
  Matrix(const Matrix &rhs);
  Matrix &operator=(const Matrix &rhs);
  void setAt(unsigned int x, unsigned int y, T element);
  T getAt(unsigned int x, unsigned int y) const;
  void transpose();

  void printmatr();

 private:
  T **matr;
  int rows;
  int cols;

  void fillMatrix();
  void deallocate();
  void copyMat(const Matrix &rhs);
};

template <class T>
Matrix<T>::Matrix() : rows(2), cols(2) {
  fillMatrix();
}

template <class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  fillMatrix();
}

template <class T>
Matrix<T>::~Matrix() {
  deallocate();
}

template <class T>
Matrix<T>::Matrix(const Matrix &rhs) {
  copyMat(rhs);
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix &rhs) {
  if (this != &rhs) {
    copyMat(rhs);
  }
  return *this;
}

template <class T>
void Matrix<T>::setAt(unsigned int x, unsigned int y, T element) {
  if (x < 1 || y < 1 || x > rows || y > cols) {
    std::cout << "Invalid coordinates!\n";
    return;
  }
  x -= 1;
  y -= 1;

  matr[x][y] = element;
}

template <class T>
T Matrix<T>::getAt(unsigned int x, unsigned int y) const {
  if (x < 1 || y < 1 || x > rows || y > cols) {
    std::cout << "Invalid coordinates!\n";
    return;
  }
  x -= 1;
  y -= 1;

  return matr[x][y];
}

template<class T>
void Matrix<T>::transpose(){
    Matrix<T> temp(this->cols,this->rows);
    for(int i = 0; i < temp.rows; i++){
        for(int j = 0; j< temp.cols; j++){
            temp.matr[i][j] = matr[j][i];
        }
    }
    *this = temp;
}

template <class T>
void Matrix<T>::fillMatrix() {
  matr = new T *[rows];
  for (int i = 0; i < rows; i++) {
    matr[i] = new T[cols];
  }

}

template <class T>
void Matrix<T>::deallocate() {
  for (int i = 0; i < rows; i++) {
    delete[] matr[i];
  }
  delete[] matr;
}

template <class T>
void Matrix<T>::printmatr() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matr[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

template <class T>
void Matrix<T>::copyMat(const Matrix &rhs) {
  deallocate();
  rows = rhs.rows;
  cols = rhs.cols;
  fillMatrix();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matr[i][j] = rhs.matr[i][j];
    }
  }
}