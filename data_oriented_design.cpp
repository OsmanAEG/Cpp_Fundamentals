#include <benchmark/benchmark.h>
#include <algorithm>
#include <iterator>
#include <vector>

struct int_struct{
  int a0 = 0;
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;
  int a4 = 0;
  int a5 = 0;
  int a6 = 0;
  int a7 = 0;
  int a8 = 0;
  int a9 = 0;
  int a10 = 0;
  int a11 = 0;
  int a12 = 0;
  int a13 = 0;
  int a14 = 0;
  int a15 = 0;

  void increment_a0(){
    a0++;
  }
};

struct struct_of_arrays{
  struct_of_arrays(int N){
    a0s.resize(N);
    a1s.resize(N);
    a2s.resize(N);
    a3s.resize(N);
    a4s.resize(N);
    a5s.resize(N);
    a6s.resize(N);
    a7s.resize(N);
    a8s.resize(N);
    a9s.resize(N);
    a10s.resize(N);
    a11s.resize(N);
    a12s.resize(N);
    a13s.resize(N);
    a14s.resize(N);
    a15s.resize(N);
  }

  void update_a0(){
    for(auto &a0 : a0s){
      a0++;
    }
  }

  std::vector<int> a0s;
  std::vector<int> a1s;
  std::vector<int> a2s;
  std::vector<int> a3s;
  std::vector<int> a4s;
  std::vector<int> a5s;
  std::vector<int> a6s;
  std::vector<int> a7s;
  std::vector<int> a8s;
  std::vector<int> a9s;
  std::vector<int> a10s;
  std::vector<int> a11s;
  std::vector<int> a12s;
  std::vector<int> a13s;
  std::vector<int> a14s;
  std::vector<int> a15s;
};

static void array_of_structs_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  std::vector<int_struct> A;
  std::fill_n(std::back_inserter(A), N, int_struct());

  while(s.KeepRunning()){
    for(auto &element : A){
      element.increment_a0();
    }
  }
}

BENCHMARK(array_of_structs_bench)->DenseRange(8, 16);

static void struct_of_arrays_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  struct_of_arrays A(N);

  while(s.KeepRunning()){
    A.update_a0();
  }
}

BENCHMARK(struct_of_arrays_bench)->DenseRange(8, 16);

BENCHMARK_MAIN();

