#include <iostream>
#include <typeinfo>

// outputs the size of a given variable
template<typename Variable_type>
auto variable_size(Variable_type v){
  std::cout << "The variable value is: " << v
            << " and its size is " << sizeof(v) << " bytes!"
            << " Its type is " << typeid(v).name() << std::endl;
}

int main(){
  // creating some variables
  char c = 'o';
  int i = 5;
  float f = 5.5;
  double d = 5.5;

  // output
  variable_size(c);
  variable_size(i);
  variable_size(f);
  variable_size(d);
}