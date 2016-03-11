#ifndef VERTEX_H
#define VERTEX_H
class Vertex {
public:
	Vertex();
	Vertex(Vertex *v);
	Vertex(double x, double y);
	~Vertex();
	double getX() const;
	double getY() const;
        friend ostream & operator<<(ostream &os, const Vertex &v);
private:
	double x;
	double y;
};
#endif
