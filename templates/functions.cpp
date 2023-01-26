#include <iostream>

template<typename Scalar_T1, typename Scalar_T2>
auto add(const Scalar_T1 a, const Scalar_T2 b){
  return a + b;
}

int main(){
  double x;
  int y;

  x = 55.36;
  y = 23;

  auto z = add(x, y);

  std::cout << "The sum of " << x << " and " << y << " is " << z << std::endl;
}