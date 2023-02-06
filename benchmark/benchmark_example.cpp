#include <benchmark/benchmark.h>
#include <vector>
#include <limits>
#include "random_vector.h"

static void bench(benchmark::State &state){
  // input size
  int bytes = 1 << state.range(0);

  // share size for data and index
  int count = (bytes/sizeof(int)/2);

  // vector of random values
  std::vector<int> A;

  for(auto i : random_vector(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), count)){
    A.push_back(i);
  }

  // vector of random indices
  std::vector<int> index;
  for(auto i : random_vector(0, count, count)){
    index.push_back(i);
  }

  // randomly access vector
  while(state.KeepRunning()){
    long sum = 0;
    for(int i : index){
      sum += A[i];
    }

    // don't optimize sum
    benchmark::DoNotOptimize(sum);
  }

  // set bytes processed
  state.SetBytesProcessed(long(state.iterations())*long(bytes));

  // custom label
  state.SetLabel(std::to_string(bytes/1024) + "kb");
}

// benchmark
BENCHMARK(bench)->DenseRange(13, 26)->ReportAggregatesOnly(true);

// main function
BENCHMARK_MAIN();