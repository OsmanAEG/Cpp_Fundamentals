#include "interface.h"

int main(){
  Car car1("ABC-123", 2003, "Four-Door");
  Truck truck1("456-DEF", 2017, 7);

  Vehicle v1("VANITY", 1975);

  std::cout << car1.getDescription() << std::endl;
  std::cout << truck1.getDescription() << std::endl;

  std::cout << v1.getDescription() << std::endl;

  Vehicle *v2 = &car1;
  Vehicle *v3 = &truck1;

  std::cout << v2->getDescription() << std::endl;
  std::cout << v3->getDescription() << std::endl;
}