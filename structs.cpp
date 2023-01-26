#include <iostream>

struct CAD{
  int dollars;
  int cents;

  CAD(const int dollars_in = 0, const int cents_in = 0):
    dollars(dollars_in),
    cents(cents_in){}
};

CAD operator+(const CAD a, const CAD b){
  CAD c(0, 0);
  c.cents = a.cents + b.cents;
  c.dollars = a.dollars + b.dollars;

  if(c.cents > 100){
    c.dollars += 1;
    c.cents -= 100;
  }

  return c;
}

int main(){
  CAD A(80, 81);
  CAD B(21, 56);

  CAD C = A + B;

  std::cout << "The total value is: $"
            << C.dollars
            << "."
            << C.cents
            << std::endl;
}