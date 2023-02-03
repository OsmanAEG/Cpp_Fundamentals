#include <iostream>
#include <map>
#include <string>

// output map
template<typename Map_type>
void output_map(Map_type map, std::string title){
  std::cout << title << std::endl;
  for(auto it = map.begin(); it != map.end(); ++it){
    std::cout << "Key: " << it->first
              << " Value: " << it->second << std::endl;
  }
  std::cout << std::endl;
}

// double scalar value
template<typename Scalar_type>
auto double_it(Scalar_type A){
  return A+A;
}

int main(){
  // double it map
  std::map<int, int> om;

  om[12] = double_it(12);
  om[16] = double_it(16);
  om[3]  = double_it(3);
  om[8]  = double_it(8);

  output_map(om, "Double it Map");

  // string map
  std::map<std::string, double> games_ign;
  games_ign.insert(std::make_pair("Valorant", 9.0));
  games_ign.insert(std::make_pair("MW2", 7.7));
  games_ign.insert(std::make_pair("Minecraft", 9.0));
  games_ign.insert(std::make_pair("Pokemon Sapphire", 9.5));

  output_map(games_ign, "IGN Game Ratings");

}