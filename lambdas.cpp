#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct gpu{
  std::string name;
  int tdp;

  gpu(std::string name_in, int tdp_in){
    name = name_in;
    tdp = tdp_in;
  }
};

int main(){
  std::vector<gpu> gpus{
    gpu("RTX 3080", 320),
    gpu("RX 6800 XT", 300),
    gpu("RTX 3090", 350),
    gpu("RX 6600 XT", 160),
    gpu("RTX 3060", 170),
    gpu("RTX 3070", 220)
  };

  auto tdp_sort = [](const gpu &gpu1, const gpu &gpu2) -> bool{
    return gpu1.tdp > gpu2.tdp;
  };

  std::sort(gpus.begin(), gpus.end(), tdp_sort);

  std::cout << "Sorted GPU List" << std::endl;

  for(const auto &some_gpu : gpus){
    std::cout << "GPU Name: " << some_gpu.name
              << "GPU TDP: " << some_gpu.tdp
              << std::endl;
  }
}