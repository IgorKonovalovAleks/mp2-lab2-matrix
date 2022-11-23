// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz <= 0 || sz > MAX_VECTOR_SIZE)
      throw out_of_range("Invalid size of vector");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    if(arr == nullptr)
        throw exception();
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      if(v.pMem == nullptr)
          throw exception();
      pMem = new T[v.sz];
      sz = v.sz;
      std::copy(v.pMem, v.pMem + v.sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = v.pMem;
      sz = v.sz;
      v.pMem = nullptr;
  }
  ~TDynamicVector()
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      pMem = new T[v.sz];
      sz = v.sz;
      std::copy(v.pMem, v.pMem + v.sz, pMem);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      pMem = v.pMem;
      sz = v.sz;
      v.pMem = nullptr;
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= 0 && (ind < (unsigned long long)sz))
          return pMem[ind];
      else
          throw exception();
  }
  const T& at(size_t ind) const
  {
      if (ind >= 0 && ind < sz)
          return pMem[ind];
      else
          throw exception();
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (v.sz != sz)
          return false;
      else
          for (int i = 0; i < sz; i++)
              if (v[i] != pMem[i])
                  return false;
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (v.sz != sz)
          return true;
      else
          for (int i = 0; i < sz; i++)
              if (v[i] != pMem[i])
                  return true;
      return false;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector tdv(sz);
      for (int i = 0; i < sz; i++)
          tdv[i] = pMem[i] + val;
      return tdv;
  }
  TDynamicVector operator-(double val)
  {
      TDynamicVector tdv(sz);
      for (int i = 0; i < sz; i++)
          tdv[i] = pMem[i] - val;
      return tdv;
  }
  TDynamicVector operator*(double val)
  {
      TDynamicVector tdv(sz);
      for (int i = 0; i < sz; i++)
          tdv[i] = pMem[i] * val;
      return tdv;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw "cannot sum vectors of different length";

      TDynamicVector tdv(sz);
      for (int i = 0; i < sz; i++) {
          tdv[i] = pMem[i] + v[i];
      }

      return tdv;

  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw "cannot sub vectors of different length";

      TDynamicVector tdv(sz);
      for (int i = 0; i < sz; i++) {
          tdv[i] = pMem[i] + v[i];
      }

      return tdv;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw "cannot mul vectors of different length";

      T res = (T)0;
      for (int i = 0; i < sz; i++) {
          res += pMem[i] * v[i];
      }

      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (s < 0 || s > MAX_MATRIX_SIZE)
          throw exception();
      for (size_t i = 0; i < sz; i++)
          pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::at;

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {

      return TDynamicVector<TDynamicVector<T>>::operator*(val);
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      

      if (size() != v.size())
          throw exception();

      TDynamicVector<T> tmp(sz);

      for (size_t i = 0; i < sz; i++)
          tmp[i] = pMem[i] * v[i];

      return tmp;

  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw exception();
          return TDynamicMatrix();
      }
      TDynamicMatrix tdm(sz);
      for (int i = 0; i < sz; i++)
          tdm[i] = pMem[i] + m[i];

      return tdm;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {

      if (sz != m.sz) {
          throw exception();
          return TDynamicMatrix();
      }

      TDynamicMatrix tdm(sz);
      for (int i = 0; i < sz; i++)
          tdm[i] = pMem[i] - m[i];

      return tdm;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      
      if (m.sz != sz) {
          throw exception();
          return TDynamicMatrix();
      }

      TDynamicMatrix tdm(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              tdm[i][j] = 0;
              for (int k = 0; k < sz; k++) {
                  tdm[i][j] += pMem[i][k] * m[k][j];
              }
          }
      }
      return tdm;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          istr >> v.pMem[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          ostr << v.pMem[i] << '\n';
      }
      return ostr;
  }
};

#endif
