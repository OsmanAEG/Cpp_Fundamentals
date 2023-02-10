#include <string>
#include <cstdlib>
#include <iostream>

void* operator new(size_t N){
  std::cout << "Allocating " << N << "bytes!" << std::endl;
  return malloc(N);
}

int main(){
  size_t string_bytes = sizeof(std::string);
  std::cout << "The size of string is " << string_bytes << " bytes!" << std::endl;

  for(size_t i = 0; i < string_bytes; ++i){
    std::string s_i(i, 'X');
    std::cout << i << ": " << s_i << std::endl;
  }

  return 0;
}