#include <iostream>

// defining some 2D point
class point{
public:
  void update(double x_new, double y_new);
  void print();

private:
  double x;
  double y;
};

// point class functions
void point::update(double x_new, double y_new){
  x = x_new;
  y = y_new;
}

void point::print(){
  std::cout << "point: (" << x << ", " << y << ")" << std::endl;
}

// defining some 2D vector
class vector{
public:
  vector();
  vector(double x1, double y1, double x2, double y2);
  void update(double x1, double y1, double x2, double y2);
  void print();

private:
  point min;
  point max;
};

// vector class constructors
vector::vector(){
  min.update(0.0, 0.0);
  max.update(0.0, 0.0);
}

vector::vector(double x1, double y1, double x2, double y2){
  min.update(x1, y1);
  max.update(x2, y2);
}

void vector::update(double x1, double y1, double x2, double y2){
  min.update(x1, y1);
  max.update(x2, y2);
}

void vector::print(){
  min.print();
  max.print();
}
