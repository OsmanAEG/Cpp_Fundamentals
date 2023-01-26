#include <iostream>
#include <vector>

// returns pointer allocated on the stack
int* bad_return_ptr(){
  int c = 5;
  return &c;
}

// returns variable allocated on the heap
int* good_return_ptr(){
  int *c = new int;
  *c = 8;
  return c;
}

void output(int* b){
  std::cout << "Address: " << b << ", Value: " << *b << std::endl;
}

int main(){
  if(true){
    double x = 82.0;
  }

  int *a = bad_return_ptr();
  int *b = good_return_ptr();

  output(b);

  delete b;

  std::vector<int*> pointer_vector;

  int N = 5;

  for(int i = 0; i < N; ++i){
    b = good_return_ptr();
    pointer_vector.push_back(b);
  }

  delete b;

  for(int i = 0; i < pointer_vector.size() - 1; ++i){
    output(pointer_vector[i]);
  }

  int *arr = new int[N];
  delete[] arr;
}