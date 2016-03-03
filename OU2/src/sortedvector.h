#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include <iostream>

using namespace std;

template <class T, int size> class SortedVector
{
public:
  template <class T, int size> SortedVector<T,size>::SortecVector() : 
    size(size) {}
  ~SortedVector();
  bool add(const T& v);
  T& median();
  void removeLarger(const T& v);
  void print(ostream &os);
private:
  int size;
  T vec[size];
}

#endif //SORTEDVECTOR_H
