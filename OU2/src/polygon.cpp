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

int Polygon::numVertices() { return nVertices; }

double Polygon::area()
{
  // sum x(i)*y(i+1) - x(i+1)*y(i) for all neighbouring vertices.
  // Start out with last and first vertices, to handle the wrap-around case,
  // and then loop over all remaining vertex pairs.
  Vertex *v1 = &vertices[nVertices];
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

double Polygon::maxx()
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

double Polygon::minx()
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

double Polygon::maxy()
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

double Polygon::miny()
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
