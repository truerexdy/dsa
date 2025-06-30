#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

void toh(char src, char temp, char dest, int n){
    if(n<1){
        return;
    }
    toh(src, dest, temp, n-1);
    std::cout << src << " -> " << dest << std::endl;
    toh(temp, src, dest, n-1);
    return;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cerr << "Must pass the number of rings as arguement." << std::endl;
        return 1;
    }
    int n = 0;
    try{
        n = std::stoi(argv[1]);
        if(n<1){
            throw std::runtime_error("Arguement must be a natural number");
        }
    }
    catch(std::exception& e){
        std::string err = e.what();
        std::string temp = "stoi";
        if(err == temp){
            std::cerr << "Enter a numeric value." << std::endl;
        }
        else{
            std::cerr << err << std::endl;
        }
    }
    toh('A', 'B', 'C', n);
    return 0;
}
