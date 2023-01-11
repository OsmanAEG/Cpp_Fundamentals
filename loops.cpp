#include <iostream>
#include <random>


int main(){
  // vector addition (for loop)
  const size_t N = 5;
  std::vector<int> a(N, 0);
  std::vector<int> b(N, 0);
  std::vector<int> c(N, 0);

  std::fill(a.begin(), a.end(), 2.0);
  std::fill(b.begin(), b.end(), 3.0);

  for(int i = 0; i < N; ++i){
    c[i] = a[i] + b[i];
  }

  // verifying results (while loop)
  int counter = 0;

  while(counter < N){
    if(c[counter] != 5.0){
      throw std::runtime_error("The calculated results are incorrect!");
    }

    counter++;
  }

  std::cout << "The calculated results are correct!" << std::endl;

  counter = 0;

  // printing the results (do loop)
  do{
    std::cout << "The result for element "
              << counter << " is: " << a[counter]
              << " + " << b[counter] << " = "
              << c[counter] << "\n";
    counter++;
  }while(counter < N);

  return 0;
}