#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename Vector_type>
auto value_input(Vector_type vec, int N, int it){
  if(it){
    std::cout << "FUNCTION: Value Input" << std::endl;
    std::cout << "SIZE: " << vec.size()
              << "CAPACITY: " << vec.capacity() << std::endl;
  }

  int allocs = 0;
  int cap = vec.capacity();

  for(int i = 0; i < N; ++i){
    vec.push_back(i);

    if(vec.capacity() > cap){
      cap = vec.capacity();
      allocs++;
    }
  }

  if(it){
    std::cout << "ALLOCATIONS: " << allocs << std::endl;
    std::cout << "CAPACITY: " << vec.capacity() << "\n" << std::endl;
  }

  return vec;
}

template<typename Vector_type>
auto value_input_rval_ref_1(Vector_type&& vec, int N, int it){
  if(it){
    std::cout << "FUNCTION: Value Input REF 1" << std::endl;
    std::cout << "SIZE: " << vec.size()
              << "CAPACITY: " << vec.capacity() << std::endl;
  }

  int allocs = 0;
  int cap = vec.capacity();

  for(int i = 0; i < N; ++i){
    vec.push_back(i);

    if(vec.capacity() > cap){
      cap = vec.capacity();
      allocs++;
    }
  }

  if(it){
    std::cout << "ALLOCATIONS: " << allocs << std::endl;
    std::cout << "CAPACITY: " << vec.capacity() << "\n" << std::endl;
  }

  return vec;
}

template<typename Vector_type>
auto value_input_rval_ref_2(Vector_type&& vec, int N, int it){
  if(it){
    std::cout << "FUNCTION: Value Input REF 2" << std::endl;
    std::cout << "SIZE: " << vec.size()
              << "CAPACITY: " << vec.capacity() << std::endl;
  }

  int allocs = 0;
  int cap = vec.capacity();

  for(int i = 0; i < N; ++i){
    vec.push_back(i);

    if(vec.capacity() > cap){
      cap = vec.capacity();
      allocs++;
    }
  }

  if(it){
    std::cout << "ALLOCATIONS: " << allocs << std::endl;
    std::cout << "CAPACITY: " << vec.capacity() << "\n" << std::endl;
  }

  return std::move(vec);
}

template<typename Vector_type>
auto value_input_ref(Vector_type& vec, int N, int it){
  if(it){
    std::cout << "FUNCTION: Value Input REF" << std::endl;
    std::cout << "SIZE: " << vec.size()
              << "CAPACITY: " << vec.capacity() << std::endl;
  }

  int allocs = 0;
  int cap = vec.capacity();

  for(int i = 0; i < N; ++i){
    vec.push_back(i);

    if(vec.capacity() > cap){
      cap = vec.capacity();
      allocs++;
    }
  }

  if(it){
    std::cout << "ALLOCATIONS: " << allocs << std::endl;
    std::cout << "CAPACITY: " << vec.capacity() << "\n" << std::endl;
  }
}

int main(int argc, char *argv[]){
  if(argc == 1){
    return 0;
  }

  std::string arg = argv[1];
  size_t pos;
  int it = std::stoi(arg, &pos);

  std::vector<int> vec;

  int N = 1000;
  int n = 10;

  for(int i = 0; i < n; ++i){
    if(i == it){
      std::cout << "FUNCTION: MAIN" << std::endl;
      std::cout << "BEFORE CLEAR: " << std::endl;
      std::cout << "SIZE: " << vec.size() << " CAPACITY:" << vec.capacity() << std::endl;
    }

    vec.clear();

    if(i == it){
      std::cout << "AFTER CLEAR:" << std::endl;
      std::cout << "SIZE: " << vec.size() << " CAPACITY:" << vec.capacity() << std::endl;
    }

    int prnt = i == it? 1 : 0;

    //vec = value_input(vec, N, prnt);
    //vec = value_input_rval_ref_1(std::move(vec), N, prnt);
    //vec = value_input_rval_ref_2(std::move(vec), N, prnt);
    value_input_ref(vec, N, prnt);
  }

  return 0;
}



