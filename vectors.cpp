#include <iostream>
#include <vector>

// output std vector
template<typename Scalar_type>
void vector_output(std::vector<Scalar_type> &vec){
  for(int i = 0; i < vec.size(); ++i){
    std::cout << vec[i] << "; ";
  }
  std::cout << std::endl;
}

int main(){
  int N = 5;
  int M = 12;
  std::vector<int> A;

  // filling the vector
  for(int i = 0; i < N; ++i){
    A.push_back(i);
  }

  // output vector A
  vector_output(A);

  // printing specific vector elements
  std::cout << "A starts with "
            << A.front()
            << " and ends with "
            << A.back() << std::endl;

  // clearing A
  A.clear();
  std::cout << "A is cleared and now is size "
            << A.size() << std::endl;

  // resizing A
  A.resize(M);
  std::cout << "The new size for A is "
            << A.size() << std::endl;

  // re-filling A
  for(int i = 0; i < M; ++i){
    A.at(i) = i;
  }

  // inserting and erasing elements
  A.insert(A.begin() + 3, 8);
  A.erase(A.begin() + 8);
  A.pop_back();

  // outputting the new vector A
  vector_output(A);

  return 0;
}