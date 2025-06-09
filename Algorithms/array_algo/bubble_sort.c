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

int main(){
    const int n=16;
    int a[n];
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        a[i] = rand()%n;
    }
    printf("Un-sorted arrar\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    bubble_sort(a,size);
    printf("\n");
    printf("Sorted arrar\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}