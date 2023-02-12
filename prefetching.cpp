#include <benchmark/benchmark.h>
#include <cstdlib>

// access array by row-major
static void row_major_access(benchmark::State &s){
  int N = 1 << 12;
  int *arr = new int[N*N];

  while(s.KeepRunning()){
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        arr[i*N+j] += j;
      }
    }
  }
}

BENCHMARK(row_major_access)->Unit(benchmark::kMillisecond);

// access array by column-major
static void column_major_access(benchmark::State &s){
  int N = 1 << 12;
  int *arr = new int[N*N];

  while(s.KeepRunning()){
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        arr[j*N+i] += j;
      }
    }
  }
}

BENCHMARK(column_major_access)->Unit(benchmark::kMillisecond);

// access array by random stride
static void random_stride_access(benchmark::State &s){
  int N = 1 << 12;
  int *arr = new int[N*N];

  while(s.KeepRunning()){
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        arr[j*N+rand()%N] += j;
      }
    }
  }
}

BENCHMARK(random_stride_access)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
