#include <iostream>
#include <memory>

int main(){
  std::shared_ptr<double> shared_double_1(new double(10));
  std::shared_ptr<double> shared_double_2 = shared_double_1;

  std::cout << "Use count of the shared double = "
            << shared_double_1.use_count()
            << std::endl;

  std::cout << "Use count of the shared double = "
            << shared_double_2.use_count()
            << std::endl;

  std::weak_ptr<double> weak_double = shared_double_1;

  std::cout << "Use count of the shared double = "
            << shared_double_1.use_count()
            << std::endl;

  std::cout << "Use count of the shared double = "
            << weak_double.use_count()
            << std::endl;

  auto shared_double_3 = weak_double.lock();

  std::cout << "Use count of the shared double = "
            << shared_double_3.use_count()
            << std::endl;

  shared_double_1.reset();
  shared_double_2.reset();

  std::cout << "Use count of the shared double = "
            << shared_double_3.use_count()
            << std::endl;

  std::cout << "Unique shared double 3 = "
            << shared_double_3.unique()
            << std::endl;

  shared_double_3.reset();

  std::cout << "Validity shared double 3 = "
            << shared_double_3.get()
            << std::endl;

  std::unique_ptr<double> unique_double(new double(20));
}