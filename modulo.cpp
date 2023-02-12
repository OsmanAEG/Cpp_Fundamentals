#include <benchmark/benchmark.h>
#include <vector>
#include <random>

// generate argument pairs
static void custom_arguments(benchmark::internal::Benchmark* b){
  for(int i = 1 << 4; i <= 1 << 10; i <<= 2){
    for(int j : {32, 128, 224}){
      b = b -> ArgPair(i, j);
    }
  }
}

static void basic_modulo_function(benchmark::State &s){
  int N = s.range(0);
  int max = s.range(1);

  std::vector<int> vector_in;
  std::vector<int> vector_out;

  vector_in.resize(N);
  vector_out.resize(N);

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> distribution(0, 225);

  for(int &element : vector_in){
    element = distribution(rng);
  }

  while(s.KeepRunning()){
    for(int i = 0; i < N; ++i){
      vector_out[i] = vector_in[i]%max;
    }
  }
}

BENCHMARK(basic_modulo_function)->Apply(custom_arguments);

static void fast_modulo_function(benchmark::State &s){
  int N = s.range(0);
  int max = s.range(1);

  std::vector<int> vector_in;
  std::vector<int> vector_out;

  vector_in.resize(N);
  vector_out.resize(N);

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> distribution(0, 225);

  for(int &element : vector_in){
    element = distribution(rng);
  }

  while(s.KeepRunning()){
    for(int i = 0; i < N; ++i){
      vector_out[i] = (vector_in[i] >= max) ? vector_in[i] % max : vector_in[i];
    }
  }
}

BENCHMARK(basic_modulo_function)->Apply(custom_arguments);

BENCHMARK_MAIN();