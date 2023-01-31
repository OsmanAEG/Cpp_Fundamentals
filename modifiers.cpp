#include <iostream>

void static_count(){
  static int count = 0;
  std::cout << "Count = " << count << std::endl;
  count++;
}

class flagClass{
private:
  mutable int accesses;
  bool flag;
public:
  flagClass(bool f){
    accesses = 0;
    flag = f;
  }

  bool get_flag() const{
    accesses++;
    std::cout << "Accesses incremented to " << accesses << std::endl;
    return flag;
  }
};

int main(){
  for(int i = 0; i < 10; ++i){
    static_count();
  }

  const flagClass fc(true);
  bool flag;

  for(int i = 0; i < 10; ++i){
    flag = fc.get_flag();
    std::cout << "Flag: " << flag << std::endl;
  }

  int non_volatile_int = 1;
  volatile int volatile_int = 1;

  for(int i = 0; i < 20; ++i){
    non_volatile_int *= 2;
  }

  for(int i = 0; i < 20; ++i){
    volatile_int *= 2;
  }

  std::cout << "Non Volatile Int = " << non_volatile_int << std::endl;
  std::cout << "Volatile Int = " << volatile_int << std::endl;

  return 0;
}