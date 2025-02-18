#include <stdio.h>

int main(){
    int n = 10;
    for(int k=0; k<n; k++){
        for(int i=0; i<k; i++){
            printf("* ");
        }
        printf("\n");
    }
}