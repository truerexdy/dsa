#include <iostream>
#include <iterator>
#define MAX 128

int n, w[MAX], v[MAX], max_w, sum_v[MAX][MAX], ind = 0;

int knap(){
    int temp = 0;
    if(n<1){
        return -1;
    }
    for(int i=0; i<n; i++){
        int curr_wsum = 0;
        for(int j=0; j<n; j++){
            if(i==j){
                continue;
            }
            if(curr_wsum+w[j] <= max_w){
                //std::cout << curr_sum << std::endl;
                curr_wsum += w[j];
                sum_v[i][j] = v[i]+v[j];
            }
        }
    }
     
    std::cout << std::endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << sum_v[i][j] << "\t";
            if(sum_v[i][j] > temp){
                temp = sum_v[i][j];
            }
        }
        std::cout << std::endl;
    }

    return temp;
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
