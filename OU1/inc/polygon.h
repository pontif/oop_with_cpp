#ifndef POLYGON_H
#define POLYGON_H
#include "vertex.h"

class Polygon {
public:
	Polygon();
//	Polygon(Polygon);
//	Polygon(Vertex *vertices);
//	add(Vertex);
//	double area();
//	double minx();
//  double maxx();
//  double miny();
//  double maxy();
	int numVertices();
private:
	Vertex *vertices;
	int nVertices;
};
#endif
