#include <iostream>

int factorial(int n){
  if(n <= 1) return 1;
  else return n*factorial(n-1);
}

int fibonacci(int n){
  if(n == 0) return 0;
  else if(n == 1) return 1;
  else return fibonacci(n-2) + fibonacci(n-1);
}

int main(){
  int n = 6;

  std::cout << "For n = " << n << "\n"
            << "Factorial(n) = " << factorial(n) << "\n"
            << "Fibonacci(n) = " << fibonacci(n) << "\n" << std::endl;
}