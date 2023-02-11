#include <benchmark/benchmark.h>
#include <cstdlib>

static void cache_associativity(benchmark::State &s){
  int M = 1 << s.range(0); // step size
  int N = 1 << 25; // array size
  int P = 10000; // number of memory access

  char *A = new char[N]; // array of characters

  // filling array
  for(int i = 0; i < N; ++i){
    A[i] = rand()%100;
  }

  // accessing memory
  while(s.KeepRunning()){
    int i = 0;
    for(int j = 0; j < P; ++j){
      A[i]++;
      i = (i+M)%N;
    }
  }

  // clear
  delete [] A;
}

BENCHMARK(cache_associativity)->DenseRange(0, 10)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();