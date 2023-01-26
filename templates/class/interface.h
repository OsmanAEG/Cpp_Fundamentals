template <typename Scalar_T>
class Point{
private:
  Scalar_T x;
  Scalar_T y;
public:
  Point(const Scalar_T x_in, const Scalar_T y_in) :
    x(x_in),
    y(y_in){}

    Scalar_T return_x(){
      return x;
    }

    Scalar_T return_y(){
      return y;
    }
};