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

void multiple_threads_single_variable(){
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

void multiple_threads_multiple_variables_same_cache_line(){
  std::vector<std::thread> threads;
  int N = 5000;
  int n = 6;
  std::vector<std::atomic<int>> As(n);

  for(int i = 0; i < n; ++i){
    std::thread thread_i([&](){increment(As[i], N);});
    threads.push_back(std::move(thread_i));
  }

  for(auto& thread : threads){
    thread.join();
  }
}

struct alignas(64) aligned_type{
  std::atomic<int> A;
};

void multiple_threads_multiple_variables_different_cache_line(){
  std::vector<std::thread> threads;
  int N = 5000;
  int n = 6;
  std::vector<aligned_type> As(n);

  for(int i = 0; i < n; ++i){
    std::thread thread_i([&](){increment(As[i].A, N);});
    threads.push_back(std::move(thread_i));
  }

  for(auto& thread : threads){
    thread.join();
  }
}

int main(){
  one_thread_execution();
  one_thread_execution();
  multiple_threads_single_variable();
  multiple_threads_multiple_variables_same_cache_line();
  multiple_threads_multiple_variables_different_cache_line();
  return 0;
}

