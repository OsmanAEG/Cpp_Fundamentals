#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <array>
#include <deque>
#include <algorithm>

template<typename Container_type>
void container_output(Container_type container, std::string title){
  std::cout << title << std::endl;
  for(auto item : container){
    std::cout << item << "; ";
  }
  std::cout << "\n" << std::endl;
}

int main(){
  const int N = 5;

  // array
  std::array<int, N> arr = {12, 3, 5, 7, 77};
  container_output(arr, "Integer Array");
  std::sort(arr.begin(), arr.end());
  container_output(arr, "Integer Array (Sorted)");

  std::cout << "--------------------------" << std::endl;

  // vector
  std::vector<int> vec;
  for(int i = 0; i < N; ++i){
    vec.push_back(i*N);
  }
  container_output(vec, "Integer Vector");
  for(int i = 0; i < N-3; ++i){
    vec.pop_back();
  }
  container_output(vec, "Integer Vector (Post Pop Back)");

  std::cout << "--------------------------" << std::endl;

  // list
  // forward lists: singly linked
  // lists: doubly linked
  std::list<int> list;
  for(int i = 0; i < N; ++i){
    list.push_back(i);
  }
  container_output(list, "Integer List");
  auto iterator = list.begin();
  list.insert(iterator, 5);
  container_output(list, "Integer List (Insert 1)");
  list.insert(iterator, 6);
  container_output(list, "Integer List (Insert 2)");
  list.insert(list.begin(), 7);
  container_output(list, "Integer List (Insert 3 - begin)");

  for(auto reverse_iterator = list.rbegin(); reverse_iterator != list.rend(); ++reverse_iterator){
    std::cout << *reverse_iterator << "; ";
  }
  std::cout << "\n" << std::endl;
  std::cout << "--------------------------" << std::endl;

  // deques
  std::deque<int> deque;
  for(int i = 0; i < N; ++i){
    deque.push_back(i);
  }
  container_output(deque, "Integer Deque");
  deque.push_back(5);
  deque.push_back(6);
  deque.push_front(7);
  container_output(deque, "Integer Deque (Back and Front Insert)");
  std::cout << "--------------------------" << std::endl;
  return 0;
}