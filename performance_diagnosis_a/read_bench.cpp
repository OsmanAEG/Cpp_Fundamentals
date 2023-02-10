#include <benchmark/benchmark.h>
#include <cstdlib>
#include <cstring>

static void read_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  float *matrix = new float[N*N];
  for(int i = 0; i < N*N; ++i){
    matrix[i] = rand()%100;
  }

  float temp = 0;

  while(s.KeepRunning()){
    for(int i = 0; i < N*N; ++i){
      temp = matrix[i];
    }
  }

  benchmark::DoNotOptimize(temp);

  s.SetItemsProcessed(N*N*s.iterations());
  s.SetBytesProcessed(sizeof(float)*N*N*s.iterations());
}

BENCHMARK(read_bench)->DenseRange(8, 10);
BENCHMARK_MAIN();