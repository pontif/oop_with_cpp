#include <iostream>
using namespace std;

#include "vertex.h"

// Default constructor
Vertex::Vertex()
{
	x = 0;
	y = 0;
}

// Copy constructor
Vertex::Vertex(Vertex *v)
{
	x = v->x;
	y = v->y;
}

Vertex::Vertex(double x, double y)
{
	this->x = x;
	this->y = y;
//	cout << "Creating Vertex at " << this << " at position {" << this->x << ", " << this->y << endl;
}

// Destructor
Vertex::~Vertex()
{
//	cout << "Destroying Vertex at " << this << " at position {" << x << ", " << y << endl;
}

// Getters/setters
double Vertex::getX() const
{
	return x;
}

double Vertex::getY() const
{
	return y;
}

ostream & operator<<(ostream &os, const Vertex &v)
{
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

