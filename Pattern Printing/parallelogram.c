#include <stdio.h>

int main(){
    int n = 5;
    for(int k=0; k<n; k++){
        for(int j=0; j<k; j++){
            printf(" ");
        }
        for(int i=0; i<n; i++){
            printf("*");
        }
        printf("\n");
    }
}