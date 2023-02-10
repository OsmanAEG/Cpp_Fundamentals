#include <benchmark/benchmark.h>
#include <cstdlib>
#include <iostream>

template<typename Scalar_type, typename Int_type>
void multiply_vec_mat(Scalar_type *matrix, Scalar_type *vector,
                      Scalar_type *result, Int_type N){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      result[i] += vector[j]*matrix[i*N + j];
    }
  }
}

static void mat_vec_mul_bench(benchmark::State &s){
  int N = 1 << s.range(0);

  float *matrix = new float[N*N];
  float *vector = new float[N];
  float *result = new float[N];

  for(int i = 0; i < N; ++i){
    vector[i] = std::rand()%100;
    result[i] = 0.0;

    for(int j = 0; j < N; ++j){
      matrix[i*N+j] = rand()%100;
    }
  }

  while(s.KeepRunning()){
    multiply_vec_mat(matrix, vector, result, N);
  }

  delete [] matrix;
  delete [] vector;
  delete [] result;

  s.SetItemsProcessed(N*N*s.iterations());
  s.SetBytesProcessed(sizeof(float)*N*(N+2)*s.iterations());
}

BENCHMARK(mat_vec_mul_bench)->DenseRange(8, 10);
BENCHMARK_MAIN();