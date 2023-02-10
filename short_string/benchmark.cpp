#include <benchmark/benchmark.h>
#include <vector>
#include <string>

static void string_benchmark(benchmark::State &s){
  int string_length = s.range(0);

  int N = 8000;

  std::vector<std::string> strings;
  strings.resize(N);

  while(s.KeepRunning()){
    for(int i = 0; i < N; ++i){
      std::string string(string_length, 'x');
      strings.push_back(string);
    }
  }
}

BENCHMARK(string_benchmark)->DenseRange(0, 32);
BENCHMARK_MAIN();