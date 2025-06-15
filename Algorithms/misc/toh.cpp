#include <cmath>
#include <iostream>
#include <math.h>

static int count = 0;

void toh(char src, char temp, char dest, int n){
    if(n<1){
        return;
    }
    toh(src, dest, temp, n-1);
    // std::cout << src << " to " << dest << std::endl;
    toh(temp, src, dest, n-1);
    count++;
}

int main(){
    for(int i=0; i<10; i++){
        count = 0;
        toh('A', 'B', 'C', i);
        int expt_out = pow(2,i)-1;
        if(count == expt_out){
            std::cout << "True for " << i << std::endl;
            // std::cout << count << "  " << expt_out << std::endl;
        }
    }
    return 0;
}

// int main(){
//     int n = 0;
//     std::cout << "Enter the number of rings:" << std::endl;
//     std::cin >> n;
//     toh('A', 'B', 'C', n);
//     std::cout << "Number of Moves: " << count << std::endl;
//     return 0;
// }
