#include <benchmark/benchmark.h>
#include <vector>
#include <execution>
#include <cstdlib>
#include <ctime>

static void sequence_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  std::srand(time(NULL));

  std::vector<int> A;
  A.reserve(N);

  for(int i = 0; i < N; ++i){
    A.emplace_back(rand()%2);
  }

  while(s.KeepRunning()){
    std::sort(std::execution::seq, A.begin(), A.end());
  }
}

BENCHMARK(sequence_bench)->DenseRange(10, 20)->Unit(benchmark::kMillisecond);

static void parallel_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  std::srand(time(NULL));

  std::vector<int> A;
  A.reserve(N);

  for(int i = 0; i < N; ++i){
    A.emplace_back(rand()%2);
  }

  while(s.KeepRunning()){
    std::sort(std::execution::par, A.begin(), A.end());
  }
}

BENCHMARK(parallel_bench)->DenseRange(10, 20)->Unit(benchmark::kMillisecond);

static void parallel_unsequenced_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  std::srand(time(NULL));

  std::vector<int> A;
  A.reserve(N);

  for(int i = 0; i < N; ++i){
    A.emplace_back(rand()%2);
  }

  while(s.KeepRunning()){
    std::sort(std::execution::par_unseq, A.begin(), A.end());
  }
}

BENCHMARK(parallel_unsequenced_bench)->DenseRange(10, 20)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();



