#ifndef POLYGON_H
#define POLYGON_H
#include "vertex.h"

class Polygon {
public:
	Polygon(void);
        Polygon(const Polygon &p);
	Polygon(Vertex *vertices, int nVertices);
	~Polygon();

        // Adds a vertex to the end of the array.
	void add(Vertex v);
	double area() const;
	double minx() const;
	double maxx() const;
	double miny() const;
	double maxy() const;
	int numVertices() const;

        const Polygon & operator=(const Polygon &p);

        bool operator>=(Polygon &p) const;
        bool operator<(Polygon &p) const;

        friend ostream & operator<<(ostream &os, const Polygon &p);
private:
        // Array of vertices. NULL if polygon vertexless.
	Vertex *vertices;
        // Number of vertices in polygon.
	int nVertices;
};
#endif //POLYGON_H
