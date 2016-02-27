#include <iostream>
using namespace std;

#include "polygon.h"

Polygon::Polygon(void)
{
	nVertices = 0;
//	cout << "Creating Polygon at " << this << " with " << this->nVertices << " vertices" << endl;
}

Polygon::Polygon(Vertex *vertices, int nVertices)
{
	this->nVertices = nVertices;
	this->vertices = new Vertex[nVertices];
	for (int i = 0; i < nVertices; i++)
	{
		this->vertices[i] = vertices[i];
	}
//	cout << "Creating Polygon at " << this << " with " << this->nVertices << " vertices" << endl;
}

Polygon::~Polygon()
{
//	cout << "Destroying Polygon at " << this << " with " << this->nVertices << " vertices" << endl;
	delete[] vertices;
}

void Polygon::add(Vertex v)
{
	Vertex *newV = new Vertex[nVertices + 1];
	for (int i = 0; i < nVertices; i++)
	{
		newV[i] = vertices[i];
	}
	if (nVertices > 0) { delete[] vertices; }
	
	newV[nVertices++] = v;
	vertices = newV;
}

int Polygon::numVertices() { return nVertices; }

double Polygon::area()
{
	Vertex *v1 = &vertices[nVertices];
	Vertex *v2 = &vertices[0];
	double area = 0;
	for (int i = 0; i < nVertices; i++)
	{
		area += v1->getX() * v2->getY() - v2->getX() * v1->getY();
		v1 = v2;
		v2++;
	}
	if (area > 0) { return area / 2; }
	else { return -area / 2; }
	
}

double Polygon::maxx()
{
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