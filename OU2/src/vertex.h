#ifndef VERTEX_H
#define VERTEX_H
class Vertex {
public:
  // Constructors (trivial destructor)
  Vertex() : x(0), y(0) {}
  Vertex(Vertex *v) : x(v->x), y(v->y) {}
  Vertex(double x, double y) : x(x), y(y) {}

  // Getters/setters for position
  double getX() const { return x; };
  double getY() const { return y; };

  // Output operator, returning "(x,y)"
  friend ostream & operator<<(ostream &os, const Vertex &v)
    {return (os << "(" << v.x << "," << v.y << ")");}

private:
  // Position parameters
  double x;
  double y;
};

#endif //VERTEX_H
