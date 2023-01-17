#include <iostream>

int main(){
  // intializing array
  int N = 5;
  int arr[N];

  for(int i = 0; i < N; ++i){
    arr[i] = i;
  }

  // pointer arithmetic
  int *arr_ptr = arr;

  for(int i = 0; i < N; ++i){
    std::cout << "arr[" << i << "]" << " = " << arr[i] << " at address " << arr_ptr << std::endl;
    arr_ptr++;
  }
}