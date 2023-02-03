#include <iostream>
#include <vector>
#include <cmath>

int main(){
  const auto pi = M_PI;
  const auto N = 10;

  std::vector<double> vec_pi;

  for(int i = 0; i < N; ++i){
    vec_pi.push_back((i+1)*pi/N);
  }

  // forward iteration
  for(auto iter = vec_pi.begin(); iter != vec_pi.end(); ++iter){
    std::cout << *iter << "; ";
  }
  std::cout << std::endl;

  // reverse iteration
  for(auto iter = vec_pi.rbegin(); iter != vec_pi.rend(); ++iter){
    std::cout << *iter << "; ";
  }
  std::cout << std::endl;

  return 0;
}