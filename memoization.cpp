#include <iostream>
#include <cstdlib>

int number_of_calls;

// fibonacci sequence functions
template<typename Int_type>
auto fibonacci_sequence(Int_type N){
  number_of_calls++;

  if(N <= 1){
    return N;
  }

  return fibonacci_sequence(N-1) + fibonacci_sequence(N-2);
}

template<typename Int_type>
auto fibonacci_sequence(Int_type N, Int_type* calculated){
  number_of_calls++;

  if(N <= 1){
    return N;
  }

  if(calculated[N] != 0){
    return calculated[N];
  }

  calculated[N] = fibonacci_sequence(N-1, calculated) + fibonacci_sequence(N-2, calculated);
  return calculated[N];
}

// helper functions
template<typename Int_type>
auto regular_fibonacci_call(Int_type N){
  return fibonacci_sequence(N);
}

template<typename Int_type>
auto memoized_fibonacci_call(Int_type N){
  Int_type *calculated = new Int_type[N + 1];

  for(int i = 0; i < N + 1; ++i){
    calculated[i] = 0;
  }

  auto answer = fibonacci_sequence(N, calculated);
  delete [] calculated;

  return answer;
}

int main(){
  number_of_calls = 0;
  int N = 20;

  // 0 or 1 for function call type
  const int function_call = 1;

  int answer = 0;

  if constexpr(function_call == 0){
    std::cout << "Regular Fibonacci Call!" << std::endl;
    answer = regular_fibonacci_call(N);
  }
  else{
    std::cout << "Memoized Fibonacci Call!" << std::endl;
    answer = memoized_fibonacci_call(N);
  }

  std::cout << "Fibonacci Computed with N = "
            << N << " and Answer = " << answer << std::endl;
  std::cout << "The Function was Called "
            << number_of_calls << " Times!" << std::endl;

  return 0;
}






