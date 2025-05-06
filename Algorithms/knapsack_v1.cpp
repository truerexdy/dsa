#include <iostream>
#define MAX 128

int n, w[MAX], v[MAX], max_w, ele[MAX], ind = 0;

int knap(){
    if(n<1){
        return -1;
    }

    int curr_wsum = 0;
    int curr_vsum = 0;

    for(int i=0; i<n; i++){
        if(curr_wsum + w[i] <= max_w){
            curr_wsum += w[i];
            curr_vsum += v[i];
            ele[ind++] = i;
        }
    }
    //std::cout << "Indices of choosen items: " << std::endl;
    /*for(int i=0; i<ind; i++){
        std::cout << ele[i] << std::endl;
    }*/
    return curr_vsum;
}


int main() {
    std::cout << "Number of Items and Max weight: " << std::endl;
    std::cin >> n >> max_w;

    if(n>MAX){
        return 1;
    }

    std::cout << "Enter weight and value:" << std::endl;
    for (int i = 0; i < n; ++i)
        std::cin >> w[i] >> v[i];

    std::cout << "Maximum value: " << knap() << std::endl;

    return 0;
}
