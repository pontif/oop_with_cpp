#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include <iostream>

using namespace std;

template <class T, int sz> class SortedVector
{
public:
  // Constructor (trivial destructor)
  SortedVector() : size(sz), nOccupied(0){}

  // Information getters
  T& median() {return vec[nOccupied / 2];}

  // Vector modifiers
  bool add(const T& v); // Returns false if vector is full
  void removeLarger(const T& v);

  // Output operator, returning string with one element per row
  void print(ostream &os);
private:
  // Static size of vector
  int size;
  // Current number of members
  int nOccupied;
  // Template vector
  T vec[sz];
};

template<class T, int sz> bool SortedVector<T, sz>::add(const T &v)
{
  if (nOccupied == size) { return false; }

  // Find first index with larger element
  int i = 0;
  while ((i < nOccupied) && (v >= vec[i])) { i++; }

  // Move all later elements one step back to make place
  int j = ++nOccupied;
  while (j > i) { vec[j] = vec[j - 1]; j--; }

  // Add new element
  vec[i] = v;
  return true;
}

template<class T, int sz> void SortedVector<T, sz>::removeLarger(const T &v)
{
  // Find first index with larger element
  int i = 0;
  while ((i < nOccupied) && (v >= vec[i])) { i++; }

  // Save new length
  int newLength = i;
  /* TODO:PF How to delete properly? */
  while (i < nOccupied) {/*delete &vec[i]*/; i++;}

  // Update length
  nOccupied = newLength;
}

template<class T, int sz> void SortedVector<T, sz>::print(ostream &os)
{
  for (int i = 0; i < nOccupied; i++) { os << "  " << vec[i] << "\n"; };
}

#endif //SORTEDVECTOR_H
