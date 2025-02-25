#include <stdio.h>
#include <stdlib.h>

int linear_search(int a[], int key, int size){
    for(int i=0; i<size; i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n = 16;
    int a[n];
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        a[i] = rand()%n;
    }
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    int key = rand()%n;
    printf("\nKey %d\n", key);
    int ind = linear_search(a,key,size);
    if(ind == -1){
        printf("Key not found.\n");
    }
    else{
        printf("Key found at index: %d\n", ind);
    }
    return 0;
}