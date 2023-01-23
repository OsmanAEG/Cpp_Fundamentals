#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <bitset>

// output N x N matrix
template<typename Scalar_type, typename Int_type>
void matrix_output(Scalar_type* A, Int_type N){
  for(int i = 0; i < N*N; ++i){
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

// multiply N x N matrices
template<typename Scalar_type, typename Int_type>
void mat_mul(Scalar_type* A, Scalar_type* B, Scalar_type* C, Int_type N){
  Scalar_type c_i;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      c_i = 0;
      for(int k = 0; k < N; ++k){
        c_i += A[i*N + k]*B[k*N + j];
      }
      C[i*N + j] = c_i;
    }
  }
}

// main function
int main(int argc, char *argv[]){
  std::fstream file_1;
  std::fstream file_2;
  std::fstream file_3;

  int N = 3;

  // opening files with different modes

  // app = append end of file
  std::cout << std::bitset<8>(std::ios::app) << std::endl;

  // ate = open and seek to end of file
  std::cout << std::bitset<8>(std::ios::ate) << std::endl;

  // in = open file for reading
  std::cout << std::bitset<8>(std::ios::in) << std::endl;

  // write = open file for writing
  std::cout << std::bitset<8>(std::ios::out) << std::endl;

  // trunc = clear file contents before opening
  std::cout << std::bitset<8>(std::ios::trunc) << std::endl;

  // combining flags
  std::cout << std::bitset<8>(std::ios::out | std::ios::in) << std::endl;

  // reading the first matrix
  file_1.open(argv[1], std::ios::in);

  // allocating memory
  int *A = (int*)malloc(N*N*sizeof(int));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      file_1 >> A[i*N + j];
    }
  }

  file_1.close();

  matrix_output(A, N);

  // reading the second matrix
  file_2.open(argv[2], std::ios::in);
  file_2 >> N;

  // allocating memory
  int *B = (int*)malloc(N*N*sizeof(int));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      file_2 >> B[i*N + j];
    }
  }

  file_2.close();

  matrix_output(B, N);

  // writing the third matrix
  file_3.open(argv[3], std::ios::out);

  // allocating memory
  int *C = (int*)malloc(N*N*sizeof(int));

  mat_mul(A, B, C, N);

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      file_3 << C[i*N + j] << ' ';
    }
  }

  file_3.close();

  return 0;
}