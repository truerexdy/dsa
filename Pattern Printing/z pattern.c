#include <stdio.h>

int main(){
    int n = 5;
    for(int i=0; i<n; i++){
        if(i==0 || i==(n-1)){
            for(int j=0; j<n; j++){
                printf("* ");
            }
        }
        else{
            for(int j=0; j<n-i-1; j++){
                printf("  ");
            }
            printf("* ");
        }
        printf("\n");
    }
}