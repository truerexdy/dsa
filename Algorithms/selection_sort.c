#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* selection_sort(int* arr, int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i; j<size; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
    return arr;
}

int main(){
    clock_t start, end;
    double cpu_time_used;
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
    start = clock();
    selection_sort(a,size);
    end = clock();
    printf("\n");
    printf("Sorted arrar\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
    printf("\nExecution Time %.2e \n", cpu_time_used);
    return 0;
}