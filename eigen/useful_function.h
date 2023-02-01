#include <stdlib.h>
#include <chrono>

// general matrix multiply
template<typename Vector_type, typename Scalar_type>
void matrix_multiplication(Vector_type &A, Vector_type &B, Vector_type &C,
                           int M, int N, int P,
                           Scalar_type F){

  Scalar_type sum_ij;

  // rows
  for(int i = 0; i < M; ++i){
    // columns
    for(int j = 0; j < N; ++j){
      sum_ij = 0;
      // element ij
      for(int k = 0; k < P; ++k){
        sum_ij += A[i][k]*B[k][j];
      }
      C[i][j] = F*sum_ij;
    }
  }
}

// initializing a random 2D std vector
template<class Scalar_type, typename Vector_type>
void initialize_std_vector_2D(Vector_type A, int M, int N, Scalar_type val = 1){
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      if(val == 1){
        A[i][j] = (Scalar_type)(rand()%100);
      }
      else{
        A[i][j] = 0;
      }
    }
  }
}

// initializing a random 2D eigen matrix
template<class Scalar_type, typename Vector_type>
void initialize_eigen_matrix_2D(Vector_type &A, int M, int N, Scalar_type val = 1){
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      if(val == 1){
        A(i, j) = (Scalar_type)(rand()%100);
      }
      else{
        A(i, j) = 0;
      }
    }
  }
}

// current time
auto current_time(){
  return std::chrono::high_resolution_clock::now();
}




