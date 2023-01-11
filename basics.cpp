#include <iostream>

template<typename Scalar_T>
void output(Scalar_T a, Scalar_T b, Scalar_T c){
  std::cout << "a + b = c" << " | so, "
            << a << " + " << b
            << " = " << c << std::endl;
}

template<typename Scalar_T>
auto addition(Scalar_T a, Scalar_T b){
  return a + b;
}

int main(){

  // strings and chars
  const char* title = "Basic Example \n";
  std::cout << title;

  bool int_calc = true;
  bool float_calc = true;

  // integer values
  int ai = 3;
  int bi = 7;

  // float values
  float af = 3.18;
  float bf = 7.58;

  if(float_calc = true){
    output(af, bf, addition(af, bf));
  }
  else{
    output(ai, bi, addition(ai, bi));
  }

  return 0;
}