#include <iostream>

struct S_test{
  char a;
  int b;
  float c;
  double d;
};

union U_test{
  S_test U_struct;
  int x;
  float y;
  double z;
};

int main(){
  // struct setup
  S_test S;
  S.a = 'a';
  S.b = 52;
  S.c = 538.6482;
  S.d = 4580.3365;

  std::cout << "The size of the struct is: " << sizeof(S) << std::endl;

  // union setup
  U_test U;
  U.U_struct = S;

  std::cout << "Size of Union: " << sizeof(U) << std::endl;
  std::cout << "Union pointer: " << &U
            << ", Field pointer: " << &(U.U_struct) << std::endl;

  int b = 8;
  U.x = b;

  std::cout << "Size of Union: " << sizeof(U) << std::endl;
  std::cout << "Union pointer: " << &U
            << ", Field pointer: " << &(U.U_struct) << std::endl;

  return 0;
}