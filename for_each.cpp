#include <iostream>
#include <vector>

int main(){
  size_t N = 8;
  std::vector<int> A;

  for(int i = 0; i < N; ++i){
    A.push_back(rand()%100);
  }

  for(auto element : A){
    std::cout << element << std::endl;
  }
}