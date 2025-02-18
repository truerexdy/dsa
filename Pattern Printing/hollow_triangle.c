#include <stdio.h>

int main(){
    int n = 5;
    for(int i=0; i<n; i++){
        if(i==n-1){
            for(int j=1; j<2*n;j++){
                printf("*");
            }
        }
        else{
            for(int j=1; j<=n-i;j++){
                printf(" ");
            }
            for(int j=0; j<=2*i;j++){
                if(j==0 || j==2*i){
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