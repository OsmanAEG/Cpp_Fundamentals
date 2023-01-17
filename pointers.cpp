#include <iostream>
void output(int value, int *ptr){
  std::cout << "value: " << value << " at address: " << &value << std::endl;
  std::cout << "pointer: " << ptr << " at address: " << &ptr << std::endl;
  std::cout << "and the pointer points to value: " << *ptr << std::endl;
  std::cout << std::endl;
}

int main(){
  int value = 40;
  int *ptr;

  ptr = &value;

  // checking output
  output(value, ptr);

  // changing the value and checking again
  value = 62;
  output(value, ptr);

  value = 20;

  // declaring new variable by using reference
  int &value_n = value;
  output(value, ptr);
}