template<class Scalar_type>
void simple_matrix_multiply(Scalar_type *A, Scalar_type *B, Scalar_type *C,
                            int M, int N, int P,
                            Scalar_type a, Scalar_type b){

  Scalar_type arr_ij;

  for(int i = 0; i < M; ++i){
    for(int j = 0; i < N; ++j){
      arr_ij = 0;

      for(int k = 0; k < P; ++k){
        arr_ij += a*A[i*P + k]*
      }
    }
  }
}
