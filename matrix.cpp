#include "matrix.h"
#include <iostream>


template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& m_): m(m_) {}

template <typename T>
int Matrix<T>::getN() const {return m.size();}

template <typename T>
int Matrix<T>::getM() const {return m[0].size();}

template <typename T>
std::vector<std::vector<T>> Matrix<T>::getMat() {return m;}

template <typename T>
Matrix<T> Matrix<T>::mul(int c){
std::vector<std::vector<int>> ma=this->getMat();
Matrix<T> mat=Matrix<T>(ma);
std::vector<std::vector<T>> matrix=mat.m;
int n=this->getN();
int m=this->getM();
for (int i=0; i<n;i++){
for ( int j=0; j<m;j++){
matrix[i][j]=matrix[i][j]*c;
}
}
mat.m=matrix;
return mat;
}

template <typename T>
Matrix<T> Matrix<T>::mul( Matrix<T> right){
std::vector<std::vector<int>> ma;
Matrix<T> mat=Matrix<T>(ma);
std::vector<std::vector<T>> matrix=mat.m;
int n=this->getN();
int m=right.getM();
int sum=0;
for (int i=0;i<n;i++){
matrix.push_back({});
for (int j=0; j<m; j++){
matrix[i].push_back(0);
}
}
for (int k=0; k<right.getM(); k++){
for (int i=0; i< this->getN(); i++){
sum=0;
for (int j=0; j<right.getN(); j++){
sum=sum+(this->m[i][j]*right.m[j][k]);
}
matrix[i][k]=sum;
}
}
mat.m=matrix;
return mat;
}


template <typename T>
Matrix<T> operator+(const Matrix<T> right, const Matrix<T> left){
    std::vector<std::vector<T>> mat;
    std::vector<std::vector<T>> ml=left.m;
    std::vector<std::vector<T>> mr=right.m;
    T sum=0;
    int n=left.getN();
    int m=right.getM();
    for (int i=0;i<n;i++){
    mat.push_back({});
    for (int j=0; j<m; j++){
    sum=ml[i][j]+mr[i][j];
    mat[i].push_back(sum);
    }
    }
    Matrix<T> matr(mat);
    return matr;
}

template <typename T>
Matrix<T> operator-(const Matrix<T> right, const Matrix<T> left){
    std::vector<std::vector<T>> mat;
    std::vector<std::vector<T>> ml=left.m;
    std::vector<std::vector<T>> mr=right.m;
    T sum=0;
    int n=left.getN();
    int m=right.getM();
    for (int i=0;i<n;i++){
    mat.push_back({});
    for (int j=0; j<m; j++){
    sum=ml[i][j]-mr[i][j];
    mat[i].push_back(sum);
    }
    }
    Matrix<T> matr(mat);
    return matr;
}

template <typename T>
Matrix<T> operator*(const int c,const Matrix<T> right){
Matrix<T> mat = right;
std::vector<std::vector<T>> matrix=mat.m;
int n=right.getN();
int m=right.getM();
for (int i=0; i<n;i++){
for ( int j=0; j<m;j++){
matrix[i][j]=matrix[i][j]*c;
}
}
mat.m=matrix;
return mat;
}


template <typename T>
Matrix<T> operator*(const Matrix<T> left, const Matrix<T> right){
std::vector<std::vector<T>> ma;
Matrix<T> mat=Matrix<T>(ma);
std::vector<std::vector<T>> matrix=mat.m;
int n=left.getN();
int m=right.getM();
T sum=0;
for (int i=0;i<n;i++){
matrix.push_back({});
for (int j=0; j<m; j++){
matrix[i].push_back(0);
}
}
for (int k=0; k<right.getM(); k++){
for (int i=0; i< left.getN(); i++){
sum=0;
for (int j=0; j<right.getN(); j++){
sum=sum+(left.m[i][j]*right.m[j][k]);
}
matrix[i][k]=sum;
}
}
mat.m=matrix;
return mat;
}


template <typename T>
bool operator==(const Matrix<T> right, const Matrix<T> left) {
    bool e=true;
    int n=left.getN();
    int m=right.getM();
    for (int i=0;i<n;i++){
    for (int j=0; j<m; j++){
    if (left.m[i][j]!=right.m[i][j]){
        e=false;
    }
    }
    }

    return e;
}


template <typename T>
bool operator!=(const Matrix<T> right, const Matrix<T> left){
    bool e=true;
    Matrix<T> mat=Matrix<T>(left.m);
    if (mat==right){
        e=false;
    }
    return e;
}


