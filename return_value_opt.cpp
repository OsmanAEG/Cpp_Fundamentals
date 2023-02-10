#include <cstdlib>
#include <vector>
#include <iostream>

struct SomeString{
  std::string a;
  SomeString(std::string a_in) : a(a_in) {}
  SomeString(const SomeString &b){
    std::cout << "Copied String." << std::endl;
    a = b.a;
  }
};

SomeString return_value_optimization(){
  SomeString message("Hello there.");
  return message;
}

SomeString no_return_value_optimization(int check){
  SomeString message_a("Hello there.");
  SomeString message_b("Hello there (kenobi accent).");

  if(check){
    return message_a;
  }
  else{
    return message_b;
  }
}

int main(){
  srand(time(NULL));
  int check = rand()%2;

  std::cout << "Return Value with Optimization" << std::endl;
  auto x = return_value_optimization();

  std::cout << "No Return Value with Optimization" << std::endl;
  auto y = no_return_value_optimization(check);

  std::cout << "First String Return: " << x.a << std::endl;
  std::cout << "Second String Return: " << y.a << std::endl;

  return 0;
}
