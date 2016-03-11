#include <iostream>
using namespace std;

#include "polygon.h"

// Default constructor
Polygon::Polygon(void)
{
  vertices = NULL;
  nVertices = 0;
//cout << "Creating Polygon at " << this << " with " << this->nVertices << " vertices" << endl;
}

Polygon::Polygon(const Polygon &p)
{
  nVertices = p.nVertices;
  vertices = new Vertex[nVertices];
  for (int i = 0; i < nVertices; i++)
  {
    vertices[i] = p.vertices[i];
  }
}

Polygon::Polygon(Vertex *vertices, int nVertices)
{
  this->nVertices = nVertices;
  // Allocate memory for vertices in the new polygon
  this->vertices = new Vertex[nVertices];
  // Copy all members of array of vertices to new polygon
  for (int i = 0; i < nVertices; i++)
  {
    this->vertices[i] = vertices[i];
  }
//	cout << "Creating Polygon at " << this << " with " << this->nVertices << " vertices" << endl;
}

// Destructor. Deallocates array of vertices.
Polygon::~Polygon()
{
//	cout << "Destroying Polygon at " << this << " with " << this->nVertices << " vertices" << endl;
  if (vertices != NULL) { delete[] vertices; }
}

void Polygon::add(Vertex v)
{
  // Allocate new array of vertices, with space for the vertex to be added
  Vertex *newV = new Vertex[nVertices + 1];

  // Copy vertices from old polygon to the new polygon
  for (int i = 0; i < nVertices; i++)
  {
    newV[i] = vertices[i];
  }

  // Deallocate memory for the old array of vertices
  if (nVertices > 0) { delete[] vertices; }

  // Add new vertex to array of vertices
  newV[nVertices++] = v;

  // Set vertices to point to new array of vertices
  vertices = newV;
}

int Polygon::numVertices() const { return nVertices; }

double Polygon::area() const
{
  // sum x(i)*y(i+1) - x(i+1)*y(i) for all neighbouring vertices.
  // Start out with last and first vertices, to handle the wrap-around case,
  // and then loop over all remaining vertex pairs.
  Vertex *v1 = &vertices[nVertices - 1];
  Vertex *v2 = &vertices[0];
  double area = 0;
  for (int i = 0; i < nVertices; i++)
  {
    area += v1->getX() * v2->getY() - v2->getX() * v1->getY();
    v1 = v2;
    v2++;
  }
  // Return sum divided by 2, and negate if negative.
  if (area > 0) { return area / 2; }
  else { return -area / 2; }
}

double Polygon::maxx() const
{
  // Loop over all vertices to find the extreme value
  double maxX = vertices[0].getX();
  for (int i = 1; i < nVertices; i++)
  {
    if (vertices[i].getX() > maxX)
    {
      maxX = vertices[i].getX();
    }
  }
  return maxX;
}

double Polygon::minx() const
{
  // Loop over all vertices to find the extreme value
  double minX = vertices[0].getX();
  for (int i = 1; i < nVertices; i++)
  {
    if (vertices[i].getX() < minX)
    {
      minX = vertices[i].getX();
    }
  }
  return minX;
}

double Polygon::maxy() const
{
  // Loop over all vertices to find the extreme value
  double maxY = vertices[0].getY();
  for (int i = 1; i < nVertices; i++)
  {
    if (vertices[i].getY() > maxY)
    {
      maxY = vertices[i].getY();
    }
  }
  return maxY;
}

double Polygon::miny() const
{
  // Loop over all vertices to find the extreme value
  double minY = vertices[0].getY();
  for (int i = 1; i < nVertices; i++)
  {
    if (vertices[i].getY() < minY)
    {
      minY = vertices[i].getY();
    }
  }
  return minY;
}

const Polygon & Polygon::operator=(const Polygon &p)
{
  if (this != &p)
  {
    nVertices = p.nVertices;
    delete[] vertices;
    vertices = new Vertex[nVertices];
    for (int i = 0; i < nVertices; i++)
    {
      vertices[i] = p.vertices[i];
    }
  }
  return *this;
}

bool Polygon::operator>=(Polygon &p) const
{
  bool geq = false;
  if (p.area() <= area()) { geq = true; }
  return geq;
}

bool Polygon::operator<(Polygon &p) const
{
  return !(*this >= p);
}

ostream & operator << (ostream &os, const Polygon &p)
{
  os << "{";
  for (int i = 0; i < p.nVertices; i++)
  {
    os << p.vertices[i] << " ";
  }
  os << "}";
  return os;
}

