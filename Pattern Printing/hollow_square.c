#include <stdio.h>

int main(){
    int n = 5;
    for(int i=0; i<n; i++){
        if(i==0 || i==n-1){
            for(int j=0; j<n; j++){
                printf("*");
            }
            printf("\n");
        }
        else{
            for(int j=0; j<n; j++){
                if(j==0 || j==n-1){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}