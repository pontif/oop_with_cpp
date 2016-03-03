#ifndef POLYGON_H
#define POLYGON_H
#include "vertex.h"

class Polygon {
public:
	Polygon(void);
	Polygon(Vertex *vertices, int nVertices);
	~Polygon();
        // Adds a vertex to the end of the array.
	void add(Vertex v);
	double area();
	double minx();
	double maxx();
	double miny();
	double maxy();
	int numVertices();
private:
        // Array of vertices. NULL if polygon vertexless.
	Vertex *vertices;
        // Number of vertices in polygon.
	int nVertices;
};
#endif //POLYGON_H
