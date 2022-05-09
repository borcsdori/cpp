#include <iostream>
#include <vector>
#include "matrix.h"

int main()
{
  Matrix<int> m1 = { { // 2x5
    { 1, 2, 3, 4,  5 },
    { 6, 7, 8, 9, 10 }
  } };
  Matrix<int> m2 = { {  // 5x2
    { 1,  2 },
    { 3,  4 },
    { 5,  6 },
    { 7,  8 },
    { 9, 10 },
  } };
  const Matrix<int> m3 = { { // 5x3
    {  1,  2,  3 },
    {  4,  5,  6 },
    {  7,  8,  9 },
    { 10, 11, 12 },
    { 13, 14, 15 },
  } };

  Matrix<int> r1 = m1.mul(3);   // 2x5
  Matrix<int> r6 = -5 * m1;     // 2x5
  Matrix<int> r2 = m1.mul(m2);  // 2x2
  Matrix<int> r3 = m2 * m1;     // 5x5
  Matrix<int> r4 = m1 * m3;     // 2x3

  const Matrix<int> res1 = { {  // 2x5
    {  3,  6,  9, 12, 15 },
    { 18, 21, 24, 27, 30 }
  } };
  const Matrix<int> res6 = { {  // 2x5
    {  -5, -10, -15, -20, -25 },
    { -30, -35, -40, -45, -50 }
  } };
  const Matrix<int> res2 = { {  // 2x2
    {  95, 110 },
    { 220, 260 }
  } };
  const Matrix<int> res3 = { {  // 5x5
    {  13,  16,  19,  22,  25 },
    {  27,  34,  41,  48,  55 },
    {  41,  52,  63,  74,  85 },
    {  55,  70,  85, 100, 115 },
    {  69,  88, 107, 126, 145 }
  } };
  const Matrix<int> res4 = { { // 2x3
    { 135, 150, 165 },
    { 310, 350, 390 }
  } };

  // now test it for double parameters
  Matrix<double> md1 = { { // 2x5
    { 1, 2, 3, 4,  5 },
    { 6, 7, 8, 9, 10 }
  } };
  Matrix<double> rd1 = { { // 2x5 double
    { 0.5, 1.0, 1.5, 2.0, 2.5 },
    { 3.0, 3.5, 4.0, 4.5, 5.0 }
  } };

  if ( res1 == r1 && res6 == r6 &&
       res2 == r2 && res3 == r3 &&
       res4 == r4 && 0.5*md1 == rd1
     )
  {
    std::cerr << "Passed\n";
  }
  else
  {
    std::cerr << "Failed\n";
  }
  return 0;
}
