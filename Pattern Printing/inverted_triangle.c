#include <stdio.h>

int main(){
    int n = 10;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        for(int j=2*(n-i); j>1 ; j--){
            printf("*");
        }
        printf("\n");
    }
}