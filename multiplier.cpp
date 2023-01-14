#include <iostream>

int main(){
    int multiplier = 2;
    int x = 1;
    int N = 50;

    for(int i = 0; i < N; ++i){
        if(multiplier%2 == 0){
            multiplier++;
            std::cout << "even multiplier" << std::endl;
        }else{
            multiplier*=2;
            std::cout << "odd multiplier" << std::endl;
            continue;
        }
        x *= multiplier;
    }

    std::cout << x << std::endl;
}