#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int** matrix;
    int size;
}graph;

//Must check the size aka n(must be >0) before calling this function
graph* create_graph(int n){
    if(n<1){
        printf("Invalid Size\n");
        return NULL;
    }
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->size = n;
    temp->matrix = (int**)calloc(temp->size, temp->size*sizeof(int*));
    for(int i=0; i<temp->size; i++){
        temp->matrix[i] = (int*)calloc(temp->size, temp->size*sizeof(int));
        for(int j=0; j<temp->size; j++){
            temp->matrix[i][j] = 0;
        }
    }
    return temp;
}

void display_graph(graph* temp){
    for(int i=0; i<temp->size; i++){
        for(int j=0; j<temp->size; j++){
            printf("%d ", temp->matrix[i][j]);
        }
        printf("\n");
    }
}

void free_graph(graph* temp){
    if(!temp){
        return;
    }
    int size = temp->size;
    for(int i=0; i<size; i++){
        free(temp->matrix[i]);
    }
    free(temp->matrix);
    free(temp);
}

int main(){
    graph* temp = create_graph(10);
    display_graph(temp);
    free_graph(temp);
    return 0;
}
