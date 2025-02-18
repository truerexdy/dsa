#include <stdio.h>

int main(){
    int n = 5;
    for(int k=0; k<n; k++){
        for(int j=0; j<k; j++){
            printf(" ");
        }
        if(k==0 || k==n-1){
            for(int i=0; i<n; i++){
                printf("*");
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(i==0 || i== n-1){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}