#ifndef POLYGON_H
#define POLYGON_H
#include "vertex.h"

class Polygon {
public:
  // Constructors and destructor
  Polygon(void) : vertices(NULL), nVertices(0) {}
  Polygon(const Polygon &p);
  Polygon(Vertex *vertices, int nVertices);
  ~Polygon();
  
  // Adds a vertex to the end of the array.
  void add(Vertex v);

  // Information getters
  double area() const;
  double minx() const;
  double maxx() const;
  double miny() const;
  double maxy() const;
  int numVertices() const;
  
  // Assignment operator
  const Polygon & operator=(const Polygon &p);
  
  // Comparison operators (NOTE not a full set)
  bool operator>=(Polygon &p) const;
  bool operator<(Polygon &p) const;

  // Output operator
  friend ostream & operator<<(ostream &os, const Polygon &p);

private:
  // Array of vertices. NULL if polygon vertexless.
  Vertex *vertices;
  // Number of vertices in polygon.
  int nVertices;
};

#endif //POLYGON_H
