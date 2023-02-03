#include <iostream>
#include <unordered_map>
#include <string>

int main(){
  std::unordered_map<std::string, double> math_expressions;

  std::string PI = "PI";

  math_expressions[PI] = 3.14159265;
  math_expressions["ROOT2"] = 1.141;
  math_expressions.insert(std::make_pair("E", 2.718));

  for(auto it = math_expressions.begin(); it != math_expressions.end(); ++it){
    std::cout << "Key: "
              << it->first
              << " Value: "
              << it->second << std::endl;
  }

  std::string x = "X";
  if(math_expressions.find(x) == math_expressions.end()){
    std::cout << "Could not locate: " << x << std::endl;
  }

  return 0;
}