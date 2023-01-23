// defining some 2D vector
class vector{
public:
  double x_min;
  double y_min;
  double x_max;
  double y_max;

  vector();
  vector(double x1, double y1, double x2, double y2);

  // copy constructor
  void vector(vector &v);

  void print();
};

// vector class constructors
vector::vector(){
  x_min = 0.0;
  y_min = 0.0;
  x_max = 0.0;
  y_max = 0.0;
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
