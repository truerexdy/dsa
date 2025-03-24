#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* a, int l, int m, int h){
    if(!a){
        return;
    }

    int* left = (int*)calloc(m-l+1,sizeof(int));
    int* right = (int*)calloc(h-m,sizeof(int));

    for(int i=0; i<m-l+1; i++){
        left[i] = a[l+i];
    }
    for(int i=0; i<h-m; i++){
        right[i] = a[m+i+1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<m-l+1 && j<h-m){
        if(left[i]<right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<m-l+1){
        a[k] = left[i];
        i++;
        k++;
    }
    while(j<h-m){
        a[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void merge_sort(int* a, int l, int h){
    if(!a){
        return;
    }
    int m = l+((h-l)/2);
    if(l<h){
        merge_sort(a, l, m);
        merge_sort(a, m+1, h);
        merge(a,l,m,h);
    }
}


int main(){
    const int N = 5020;
    int* a = (int*)calloc(N, sizeof(int));
    for(int i=0; i<N; i++){
        a[i]=rand()%N;
    }
    printf("\nBefore:\n");
    for(int i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    clock_t start = clock();
    merge_sort(a, 0, N-1);
    clock_t end = clock();
    printf("\n");
    printf("\nAfter:\n");
    for(int i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    double exectime = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\n Exec Time: %e\n", exectime);
    return 0;
}
