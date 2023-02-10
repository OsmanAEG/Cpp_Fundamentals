#include <benchmark/benchmark.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

struct PC{
  virtual float get_number() const noexcept{
    return 1.0;
  }
};

struct CPU : PC{
  float get_number() const noexcept{
    return 2.0;
  }
};

struct GPU : PC{
  float get_number() const noexcept{
    return 3.0;
  }
};

static void aligned_call(benchmark::State &s){
  std::vector<PC*> pc_hardware;
  int N = 9000;

  std::fill_n(std::back_inserter(pc_hardware), N, new PC);
  std::fill_n(std::back_inserter(pc_hardware), N, new CPU);
  std::fill_n(std::back_inserter(pc_hardware), N, new GPU);

  float sum = 0.0;

  while(s.KeepRunning()){
    for(auto* hardware : pc_hardware){
      sum += hardware->get_number();
    }
  }
}

BENCHMARK(aligned_call);

static void unaligned_call(benchmark::State &s){
  std::vector<PC*> pc_hardware;
  int N = 9000;

  std::fill_n(std::back_inserter(pc_hardware), N, new PC);
  std::fill_n(std::back_inserter(pc_hardware), N, new CPU);
  std::fill_n(std::back_inserter(pc_hardware), N, new GPU);

  std::random_device rng;
  std::mt19937 urng(rng());
  std::shuffle(pc_hardware.begin(), pc_hardware.end(), urng);

  float sum = 0.0;

  while(s.KeepRunning()){
    for(auto* hardware : pc_hardware){
      sum += hardware->get_number();
    }
  }
}

BENCHMARK(unaligned_call);

BENCHMARK_MAIN();


