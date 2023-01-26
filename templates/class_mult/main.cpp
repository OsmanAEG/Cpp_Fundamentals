#include <iostream>
#include <cctype>
#include "interface.h"

int main(){
  Container<int> int_c(5);
  Container<char> char_c('q');

  std::cout << "Increment of 5 is " << int_c.increment() << std::endl;
  std::cout << "Increment of q " << char_c.uppercase() << std::endl;

  return 0;
}

