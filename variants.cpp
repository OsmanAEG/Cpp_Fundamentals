#include <variant>
#include <cassert>
#include <iostream>

int main(){
  std::variant<int, float> x, y;

  x = 5;

  y = std::get<int>(x);
  y = std::get<0>(x);
  y = x;

  try{
    std::get<float>(x);
  }
  catch(const std::bad_variant_access&){
    std::cout << "Float field is not active!" << std::endl;
  }
}