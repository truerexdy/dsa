
DuckDuckGo did not detect any trackers. More
Unable to verify sender identity
 
Report Spam
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* a, int l, int h){
    int i = l;
    int j = h;
    int pivot = a[l];
    while(i<j){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}

void quick_sort(int* a, int l, int h){
    if(l>=h){
        return;
    }
    int j = partition(a, l, h);
    quick_sort(a, l, j-1);
    quick_sort(a, j+1, h);
}

int main(){
    const int N = 2048;
    clock_t start = clock();
    int* a = (int*)calloc(N, sizeof(int));
    for(int i=0; i<N; i++){
        a[i]=rand()%N;
    }
    printf("\nBefore:\n");
    for(int i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    quick_sort(a, 0, N-1);
    printf("\n");
    printf("\nAfter:\n");
    for(int i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    clock_t end = clock();
    double exectime = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\n Exec Time: %e\n", exectime);
    return 0;
}
