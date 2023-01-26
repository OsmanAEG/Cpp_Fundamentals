#include "interface.h"
#include <iostream>

int main(){
  int N = 5;
  int_arr a(N);

  for(int i = 0; i < a.size; ++i){
    a.data[i] = i;
  }

  if(true){
    int_arr b = a;
  }

  for(int i = 0; i < a.size; ++i){
    std::cout << a.data[i] << std::endl;
  }

  return 0;
}