#include <iostream>
#include "functions.h"

int main(){
  const int x = 5;
  auto x_squared = square(x);
  auto x_cubed = cube(x);

  std::cout << "x*x = " << x_squared << std::endl;
  std::cout << "x*x*x = " << x_cubed << std::endl;

  return 0;
}