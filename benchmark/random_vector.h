#include <cstdlib>
#include <vector>

std::vector<int> random_vector(int start, int finish, int N){
  std::vector<int> A;
  for(int i = 0; i < N; ++i){
    A.push_back((std::rand()% finish) + start);
  }

  return A;
}