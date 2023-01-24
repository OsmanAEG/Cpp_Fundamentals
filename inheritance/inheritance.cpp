#include "interface.h"

int main(){
  Car car1("ABC-123", 2003, "Four-Door");
  Car car2("VANITY", 2018, "Two-Door");

  std::cout << "Car 1 License: " << car1.getLicense() << std::endl;
  std::cout << "Car 2 License: " << car2.getLicense() << std::endl;

  std::cout << "Car 1 Year: " << car1.getYear() << std::endl;
  std::cout << "Car 2 Year: " << car2.getYear() << std::endl;

  std::cout << "Car 1 Style: " << car1.getStyle() << std::endl;
  std::cout << "Car 2 Style: " << car2.getStyle() << std::endl;

  Truck truck1("456-DEF", 2017, 7);
  std::cout << "Truck 1 License: " << truck1.getLicense() << std::endl;
  std::cout << "Truck 1 Year: " << truck1.getYear() << std::endl;
  std::cout << "Truck 1 Bed Length: " << truck1.getBedLength() << std::endl;
}