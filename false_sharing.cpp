#include <thread>
#include <atomic>
#include <iostream>
#include <vector>

template<typename Scalar_type, typename Int_type>
void increment(std::atomic<Scalar_type>& A, Int_type N){
  for(int i = 0; i < N; ++i){
    A++;
  }
}

void one_thread_execution(){
  std::atomic<int> A;
  int N = 5000;
  int n = 6;

  A = 0;

  for(int i = 0; i < n; ++i){
    increment(A, N);
  }
}

void problematic_thread_execution(){
  std::atomic<int> A;
  std::vector<std::thread> threads;
  int N = 5000;
  int n = 6;

  A = 0;

  for(int i = 0; i < n; ++i){
    std::thread thread_i([&](){increment(A, N);});
    threads.push_back(std::move(thread_i));
  }

  for(auto& thread : threads){
    thread.join();
  }
}

int main(){
  return 0;
}

