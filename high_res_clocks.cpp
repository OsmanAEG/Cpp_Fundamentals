#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>

auto current_time(){
  return std::chrono::high_resolution_clock::now();
}

int main(){
  // Constants
  auto constexpr N = 50;

  // vectors
  std::vector<int> A(N);
  std::vector<int> B(N);
  std::vector<int> C(N);

  for(int i = 0; i < N; ++i){
    A[i] = rand()%100 + 1;
    B[i] = rand()%100 + 1;
  }

  // vector addition
  auto start = current_time();
  for(int i = 0; i < N; ++i){
    C[i] = A[i] + B[i];
  }
  auto end = current_time();

  auto time = std::chrono::duration_cast<std::chrono::duration<
                double, std::milli>>(end-start);

  // time output
  std::cout << "Task Time for Completion = "
            << time.count()
            << " ms!"
            << std::endl;

  // clearing vectors
  A.clear();
  B.clear();
  C.clear();
}