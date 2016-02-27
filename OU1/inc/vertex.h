#ifndef VERTEX_H
#define VERTEX_H
class Vertex {
public:
	Vertex();
	Vertex(Vertex *v);
	Vertex(double x, double y);
	~Vertex();
	double getX();
	double getY();
private:
	double x;
	double y;
};
#endif