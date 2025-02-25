#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* a, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int binary_search(int a[], int key, int low, int high){
    int mid;
    while(1){
        mid = (low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(key > a[mid]){
            low = mid+1;
        }
        else if(key < a[mid]){
            high = mid-1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int n=16;
    int a[n];
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        a[i] = rand()%n;
    }
    bubble_sort(a,size);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int key = rand() % n;
    printf("Key = %d\n", key);
    int ind = binary_search(a, rand() % n, 0, n);
    if(ind == -1){
        printf("Key not found.\n");
    }
    else{
        printf("Key found at index: %d\n", ind);
    }
    return 0;
}