#include <iostream>
#include <random>
#define MAX 64

char* genstr(int n){
    if(n<1){
        return NULL;
    }
    char* str = (char*)calloc(n, sizeof(char));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(33,126);
    for(int i=0; i<n; i++){
        str[i] = distrib(gen);
    }
    return str;
}

int main(){
    int n = 0;
    std::cout << "Enter the length:" << std::endl;
    std::cin >> n;
    if(n>0){
        std::cout << genstr(n) << std::endl;
    }
    return 0;
}
