#include <iostream>
#include "interface.h"

template<typename Scalar_type>
void output_point(Point<Scalar_type> k, std::string k_name){
  std::cout << "Point " << k_name << " at ("
            << k.return_x() << " , "
            << k.return_y()
            << ")" << std::endl;
}

int main(){
  Point<int> a(2, 6);
  Point<double> b(2.23, 6.55);

  output_point(a, "a");
  output_point(b, "b");
}