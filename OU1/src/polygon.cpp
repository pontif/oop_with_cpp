#include <iostream>
using namespace std;

#include "polygon.h"

Polygon::Polygon()
{
	nVertices = 0;
}

int Polygon::numVertices() { return nVertices; }