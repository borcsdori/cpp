

#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>

template <typename T>

class Matrix
{
public:
  std::vector<std::vector<T>> m;
  Matrix();
  Matrix(const std::vector<std::vector<T>>&);

  int getN() const;

  int getM() const;
  std::vector<std::vector<T>> getMat();
  Matrix<T> mul(int c);
  Matrix<T> mul(Matrix right);

  //


  };
  template <typename T>
  Matrix<T> operator*(const int c, const Matrix<T> right);

  template <typename T>
  Matrix<T> operator+(const Matrix<T> right, const Matrix<T> left);

  template <typename T>
  Matrix<T> operator-(const Matrix<T> right, const Matrix<T> left);

  template <typename T>
  Matrix<T> operator*(const Matrix<T> right, const Matrix<T> left);

  template <typename T>
  bool operator==(const Matrix<T> right, const Matrix<T> left);

  template <typename T>
  bool operator!=(const Matrix<T> right, const Matrix<T> left);

#endif // _MATRIX_H
