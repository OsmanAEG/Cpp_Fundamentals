#include "interface.h"
int main(){
  vector vec_1;
  vector vec_2(5.0, 2.0, 10.0, 6.0);

  vec_1.print();
  vec_2.print();

  vec_1.update(2.0, 8.0, 9.0, 2.0);
  vec_1.print();

  return 0;
}