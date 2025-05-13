#include <math.h>
#include <stdio.h>
#include <time.h>
#define nV 4
#define inf 999

void printMatrix(int matrix[][nV]) {
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (matrix[i][j] == inf)
                printf("%4s", "inf");
            else
                printf("%4d", matrix[i][j]);
        }
    printf("\n");
    }
}

void floydWarshall(int graph[][nV]) {
    int matrix[nV][nV], i, j, k;
    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];
    for (k = 0; k < nV; k++) {
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printMatrix(matrix);
}

int main() {
    printf("Input:\n");
    int graph[nV][nV] = {{0, 3, inf, 5},
                        {2, 0, inf, 4},
                        {inf, 1, 0, inf},
                        {inf, inf, 2, 0}
    };
    printMatrix(graph);
    printf("\nOutput:\n");
    clock_t start = clock();
    floydWarshall(graph);
    clock_t end = clock();
    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Duration: %e \n", duration);
    return 0;
}
