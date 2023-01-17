#include <iostream>

class vector2D{
public:
  double x_min;
  double y_min;
  double x_max;
  double y_max;

  void print();
};

void vector2D::print(){
  std::cout << "From: (" << x_min << "," << y_min << ")" << std::endl;
  std::cout << "To: (" << x_max << "," << y_max << ")" << std::endl;
}