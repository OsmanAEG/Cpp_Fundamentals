#include <iostream>
#include <string>

class Vehicle{
protected:
  std::string license;
  int year;

public:
  Vehicle(const std::string &myLicense, const int &myYear) :
    license(myLicense),
    year(myYear){}

  const std::string getLicense() const{
    return license;
  }

  const int &getYear() const{
    return year;
  }
};

// car inherits from vehicle
class Car : public Vehicle{
public:
  Car(const std::string &myLicense, const int myYear, const std::string myStyle) :
    Vehicle(myLicense, myYear),
    style(myStyle) {}

  const std::string &getStyle() const{
    return style;
  }

private:
  std::string style;
};

// truck inherits from vehicle
class Truck : public Vehicle{
public:
  Truck(const std::string &myLicense, const int myYear, const int myBedLength) :
    Vehicle(myLicense, myYear),
    bed_length(myBedLength) {}

  const int &getBedLength(){
    return bed_length;
  }

private:
  int bed_length;
};