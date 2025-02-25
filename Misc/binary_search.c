#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[], int key, int low, int high){
    int mid = (low+high)/2;
    if(a[mid]==key){
        return mid;
    }
    else if(key > a[mid]){
        return binary_search(a, key, mid+1, high);
    }
    else if(key < a[mid]){
        return binary_search(a, key, low, mid-1);
    }
    else{
        return -1;
    }
}

int main(){
    int a[10];
    for(int i=0; i<10; i++){
        a[i] = i;
    }
    int ind = binary_search(a, rand() % 10, 0, 10);
    if(ind == -1){
        printf("Key not found.\n");
    }
    else{
        printf("Key found at index: %d\n", ind);
    }
    return 0;
}