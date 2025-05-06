// Used to find the Minimum cost spanning tree

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// You will need to define this function elsewhere
void primsAlgorithm(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices);

int main() {
    int numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1; // Indicate an error
    }

    printf("Enter the adjacency matrix (enter 999 for no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
            // You might want to handle cases where graph[i][j] is 0 for self-loops
        }
    }


    // --- Call to Prim's Algorithm ---
    printf("\nRunning Prim's Algorithm...\n");
    primsAlgorithm(graph, numVertices);
    // --- End Call to Prim's Algorithm ---

    return 0; // Indicate successful execution
}

// Note: The implementation of primsAlgorithm function is NOT included here.
// You will need to add the actual logic for Prim's algorithm separately.
