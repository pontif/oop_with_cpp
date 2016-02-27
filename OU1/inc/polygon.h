#ifndef POLYGON_H
#define POLYGON_H
#include "vertex.h"

class Polygon {
public:
	Polygon(void);
//	Polygon(Polygon);
	Polygon(Vertex *vertices, int nVertices);
	~Polygon();
	void add(Vertex v);
	double area();
	double minx();
	double maxx();
	double miny();
	double maxy();
	int numVertices();
private:
	Vertex *vertices;
	int nVertices;
};
#endif
