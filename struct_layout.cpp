#include <iostream>

struct bad{
  int a;
  double b;

  int c;
  double d;
};

struct good{
  int a;
  int b;

  double c;
  double d;
};

struct unsafe{
  char a;
  char b;

  double c;
  double d;
};

__attribute__((packed));

int main(){
  bad a;
  good b;
  unsafe c;

  std::cout << "Bad Struct Size = " << sizeof(a) << std::endl;
  std::cout << "Good Struct Size = " << sizeof(b) << std::endl;
  std::cout << "Unsafe Struct Size = " << sizeof(c) << std::endl;

  return 0;
}