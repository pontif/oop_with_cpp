#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include <iostream>

using namespace std;

template <class T, int sz> class SortedVector
{
public:
  SortedVector();
  ~SortedVector();
  bool add(const T& v);
  T& median();
  void removeLarger(const T& v);
  void print(ostream &os);
private:
  int size;
  int nOccupied;
  T vec[sz];
};

template<class T, int sz> SortedVector<T, sz>::SortedVector() : 
  size(sz), nOccupied(0) {}

template<class T, int sz> SortedVector<T, sz>::~SortedVector() {}

template<class T, int sz> bool SortedVector<T, sz>::add(const T &v)
{
//  cout << "\nnOccupied: " << nOccupied << "\n";
//  if (nOccupied == size) { cout << "\nFull\n"; return false; }
  int i = 0;
  while ((i < nOccupied) && (v >= vec[i])) { i++; }
  int j = ++nOccupied;
  while (j > i) { vec[j] = vec[j - 1]; j--; }
  vec[i] = v;
//  print(cout);
  return true;
}

template<class T, int sz> T& SortedVector<T, sz>::median()
{
  return vec[nOccupied / 2];
}

template<class T, int sz> void SortedVector<T, sz>::removeLarger(const T &v)
{
  int i = 0;
  while ((i < nOccupied) && (v >= vec[i])) { i++; }
  int newLength = i;
  while (i < nOccupied) {i++;}
  nOccupied = newLength;
}

template<class T, int sz> void SortedVector<T, sz>::print(ostream &os)
{
  for (int i = 0; i < nOccupied; i++) { os << "  " << vec[i] << "\n"; };
}

#endif //SORTEDVECTOR_H
