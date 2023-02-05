#include <iostream>
#include <string>

int main(){
  std::string text = "Hello, World in C++17!";

  auto val1 = text.find("Hello");
  if(val1 != std::string::npos){
    std::cout << val1 << " - Hello" << std::endl;
  }

  auto val2 = text.find("World");
  if(val1 != std::string::npos){
    std::cout << val2 << " - World" << std::endl;
  }

  if(auto val = text.find("C++17"); val != std::string::npos){
    std::cout << "Found C++17 at " << val << " without leaking scope!" << std::endl;
  }

  return 0;
}