#include <iostream>

int main(){
    int n = 0;
    std::cout << "Enter the size of the square:" << std::endl;
    std::cin >> n;
    if(n < 2 || n > 7){
        std::cerr << "Invalid Size" << std::endl;
        std::cerr << "Size must be in [2,7], since 8x4=32 but number of alphabets=26" << std::endl;
        return 1;
    }
    char* top = (char*)calloc(n, sizeof(char));
    char* bottom = (char*)calloc(n, sizeof(char));
    char* left = (char*)calloc(n-2, sizeof(char));
    char* right = (char*)calloc(n-2, sizeof(char));
    char current = 'A';
    for(int i=0; i<n; i++){
        top[i] = current++;
    }
    for(int i=0; i<n-2; i++){
        right[i] = current++;
    }
    for(int i=0; i<n; i++){
        bottom[i] = current++;
    }
    for(int i=0; i<n-2; i++){
        left[i] = current++;
    }
    int l=n-3, r=0;
    for(int i=0; i<n; i++){
        if(i==0){
            for(int j=0; j<n; j++){
                std::cout << top[j];
            }
        }
        else if(i==n-1){
            for(int j=n-1; j>-1; j--){
                std::cout << bottom[j];
            }
        }
        else{
            for(int j=0; j<n; j++){
                if(j==0){
                    std::cout << left[l--];
                }
                else if(j==n-1){
                    std::cout << right[r++];
                }
                else{
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
