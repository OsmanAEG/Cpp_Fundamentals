#include <iostream>

enum lift_type{
  BENCH_PRESS = 0,
  DEADLIFT = 1,
  SQUAT = 2,
  OHP = 3
};

const char* lift_output(const lift_type lift){
  const char *outputs[] = {"Bench Press", "Squat", "Deadlift", "Over Head Press"};
  return outputs[lift];
}

int main(){
  lift_type DL = DEADLIFT;
  lift_type B = BENCH_PRESS;

  std::cout << "DL is a " << lift_output(DL)
            << " with value " << DL << std::endl;

  std::cout << "B is a " << lift_output(B)
            << " with value " << B << std::endl;
}