#include <iostream>
#include <string>

template<typename ...Args>
void output_sentence(Args... args){
  (std::cout << ... << args) << std::endl;
}

template<typename ...Args>
auto sequential_multiply(Args... args){
  return (args * ...);
}

int main(){
  output_sentence("Fold ", "expressions ", "are ", "so ", "EPIC!");
  auto x = sequential_multiply(1, 2, 3, 4, 5);
  std::cout << "5 factorial is: " << x << std::endl;
  return 0;
}