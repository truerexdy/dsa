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
    int a[10];
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<10; i++){
        a[i] = rand()%5;
    }
    int key = rand()%5;
    int ind = linear_search(a,key,size);
    if(ind == -1){
        printf("Key not found.\n");
    }
    else{
        printf("Key found at index: %d\n", ind);
    }
    return 0;
}