#include <iostream>

template<typename Scalar_type>
void plus_one(Scalar_type& x){
  x++;
}

int main(){
  double a = 1.0;
  plus_one(a);
  std::cout << a << std::endl;
}