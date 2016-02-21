#include <iostream>
using namespace std;

#include "vertex.h"
/*
Vertex::Vertex()
{
	x = 0;
	y = 0;
}
*/
Vertex::Vertex(double x, double y)
{
	this->x = x;
	this->y = y;
}
/*
Vertex::~Vertex()
{
	cout << "Destroying Vertex at " << this << " at position {" << x << ", " << y << endl;
}
*/