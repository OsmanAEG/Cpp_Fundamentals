#include <iostream>
#include <typeinfo>
#include <vector>

double sum(double x, double y){
  return x + y;
}

int main(){
  auto a = 83;
  std::cout << "Type of a is " << typeid(a).name() << std::endl;

  auto z = sum(43.2, 82);
  std::cout << "Type of z is " << typeid(z).name() << std::endl;
}