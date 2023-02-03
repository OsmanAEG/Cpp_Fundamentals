#include <iostream>
#include <string>

template<typename Variable_type>
auto variable_add(Variable_type a){
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return a;
}

template<typename Variable_type, typename... Args>
auto variable_add(Variable_type a, Args... args){
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return a + variable_add(args...);
}

int main(){
  double result = variable_add(3.1415, 2.7182, 9.81, 1.0, 0.0, 100.0);
  std::cout << "The result is: " << result << std::endl;

  return 0;
}
