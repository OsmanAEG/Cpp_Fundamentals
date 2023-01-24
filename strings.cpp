#include <iostream>
#include <string>

int main(){
  std::string a;
  std::string b;

  a = "string a";
  b = "string b";

  std::cout << "string a: " << a << "\n"
            << "string b: " << b << std::endl;

  a.swap(b);

  std::cout << "string a: " << a << "\n"
            << "string b: " << b << std::endl;

  for(int i = 0; i < a.size(); ++i){
    a.at(i) = 'x';
  }

  std::cout << "\n";

  std::cout << "string a size: " << a.size() << "\n"
            << "string a capacity: " << a.capacity() << std::endl;

  a.resize(4);
  std::cout << "\n";

  std::cout << "string a size: " << a.size() << "\n"
            << "string a capacity: " << a.capacity() << std::endl;

  a.shrink_to_fit();
  std::cout << "\n";

  std::cout << "string a size: " << a.size() << "\n"
            << "string a capacity: " << a.capacity() << std::endl;

  return 0;
}