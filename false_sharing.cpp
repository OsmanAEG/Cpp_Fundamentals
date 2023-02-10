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

auto one_thread_execution(){
  std::cout << "One Thread Increment Execution:" << std::endl;
  std::atomic<int> A;
  int N = 5000;
  int n = 6;

  A = 0;

  for(int i = 0; i < n; ++i){
    increment(A, N);
  }

  std::cout << "Incremented Iteration N:" << N << std::endl;
  std::cout << "Incremented Repetition n:" << n << std::endl;
  std::cout << "Incremented Variable A:" << A << std::endl;
  std::cout << std::endl;

}

auto multiple_threads_single_variable(){
  std::cout << "Multiple Threads Single Variable:" << std::endl;
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

  std::cout << "Incremented Iteration N:" << N << std::endl;
  std::cout << "Incremented Repetition n:" << n << std::endl;
  std::cout << "Incremented Variable A:" << A << std::endl;
  std::cout << std::endl;
}

auto multiple_threads_multiple_variables_same_cache_line(){
  std::cout << "Multiple Threads Multiple Variables One Cache Line:" << std::endl;
  int N = 5000;
  int n = 6;
  std::vector<std::atomic<int>> As(n);

  std::atomic<int> A1 = 0;
  std::atomic<int> A2 = 0;
  std::atomic<int> A3 = 0;
  std::atomic<int> A4 = 0;
  std::atomic<int> A5 = 0;
  std::atomic<int> A6 = 0;

  std::thread thread_1([&](){increment(A1, N);});
  std::thread thread_2([&](){increment(A2, N);});
  std::thread thread_3([&](){increment(A3, N);});
  std::thread thread_4([&](){increment(A4, N);});
  std::thread thread_5([&](){increment(A5, N);});
  std::thread thread_6([&](){increment(A6, N);});

  thread_1.join();
  thread_2.join();
  thread_3.join();
  thread_4.join();
  thread_5.join();
  thread_6.join();

  std::cout << "Incremented Iteration N:" << N << std::endl;
  std::cout << "Number of Threads and Variables n:" << n << std::endl;
  std::cout << "Incremented Variable A1: " << A1 << std::endl;
  std::cout << "Incremented Variable A2: " << A2 << std::endl;
  std::cout << "Incremented Variable A3: " << A3 << std::endl;
  std::cout << "Incremented Variable A4: " << A4 << std::endl;
  std::cout << "Incremented Variable A5: " << A5 << std::endl;
  std::cout << "Incremented Variable A6: " << A6 << std::endl;
  std::cout << std::endl;
}

struct alignas(64) aligned_type{
  std::atomic<int> A;
};

auto multiple_threads_multiple_variables_different_cache_line(){
  std::cout << "Multiple Threads Multiple Variables Different Cache Lines:" << std::endl;
  int N = 5000;
  int n = 6;

  aligned_type A1;
  aligned_type A2;
  aligned_type A3;
  aligned_type A4;
  aligned_type A5;
  aligned_type A6;

  A1.A = 0;
  A2.A = 0;
  A3.A = 0;
  A4.A = 0;
  A5.A = 0;
  A6.A = 0;

  std::thread thread_1([&](){increment(A1.A, N);});
  std::thread thread_2([&](){increment(A2.A, N);});
  std::thread thread_3([&](){increment(A3.A, N);});
  std::thread thread_4([&](){increment(A4.A, N);});
  std::thread thread_5([&](){increment(A5.A, N);});
  std::thread thread_6([&](){increment(A6.A, N);});

  thread_1.join();
  thread_2.join();
  thread_3.join();
  thread_4.join();
  thread_5.join();
  thread_6.join();

  std::cout << "Incremented Iteration N:" << N << std::endl;
  std::cout << "Number of Threads and Variables n:" << n << std::endl;
  std::cout << "Incremented Variable A1: " << A1.A << std::endl;
  std::cout << "Incremented Variable A2: " << A2.A << std::endl;
  std::cout << "Incremented Variable A3: " << A3.A << std::endl;
  std::cout << "Incremented Variable A4: " << A4.A << std::endl;
  std::cout << "Incremented Variable A5: " << A5.A << std::endl;
  std::cout << "Incremented Variable A6: " << A6.A << std::endl;
  std::cout << std::endl;
}

int main(){
  one_thread_execution();
  multiple_threads_single_variable();
  multiple_threads_multiple_variables_same_cache_line();
  multiple_threads_multiple_variables_different_cache_line();
  return 0;
}

