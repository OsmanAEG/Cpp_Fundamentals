#include <iostream>

struct some_struct{
  static constexpr int i = 25;
  static constexpr char w[] = "25.83";
  static constexpr const char *char_ptr = &w[0];

  static_assert(*char_ptr == '2', "Error!");
};

constexpr int fibonacci(int i){
  return (i <= 1) ? 1 : fibonacci(i - 1) + fibonacci(i-2);
}

int main(){
  constexpr int x = 6;
  constexpr double y = 63.82;

  some_struct Z;

  constexpr int answer = fibonacci(x);

  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
  std::cout << "answer = " << answer << std::endl;
  std::cout << "some_struct i = " << Z.i << std::endl;

  return 0;
}