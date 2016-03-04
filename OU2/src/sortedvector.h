#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include <iostream>

using namespace std;

template <class T, int sz> class SortedVector
{
public:
  SortedVector();
  ~SortedVector();
//  bool add(const T& v);
//  T& median();
//  void removeLarger(const T& v);
//  void print(ostream &os);
private:
  int size;
  T vec[sz];
};

template <class T, int sz> SortedVector<T, sz>::SortedVector() : 
  size(sz) {}

template<class T, int sz> SortedVector<T, sz>::~SortedVector() {}

#endif //SORTEDVECTOR_H
