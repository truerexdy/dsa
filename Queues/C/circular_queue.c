#include <stdio.h>
#include <stdlib.h>
#define MAX 32

typedef struct circular_queue {
    int array[MAX];
    int front;
    int rear;
} circular_queue;

int main() {
    circular_queue q;
    q.front = -1;
    q.rear = -1;
    while (1) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if ((q.rear + 1) % MAX == q.front) {
                printf("Queue Full\n");
            } else {
                printf("Enter the value:\n");
                int value;
                scanf("%d", &value);
                if (q.front == -1) {
                    q.front = 0;
                }
                q.rear = (q.rear + 1) % MAX;
                q.array[q.rear] = value;
            }
            break;
        case 2:
            if (q.front == -1) {
                printf("Queue Empty\n");
            } else {
                printf("Dequeued element: %d\n", q.array[q.front]);
                if (q.front == q.rear) {
                    q.front = -1;
                    q.rear = -1;
                } else {
                    q.front = (q.front + 1) % MAX;
                }
            }
            break;
        case 3:
            if (q.front == -1) {
                printf("Queue Empty\n");
            } else {
                int i = q.front;
                while (i != q.rear) {
                    printf("%d ", q.array[i]);
                    i = (i + 1) % MAX;
                }
                printf("%d\n", q.array[i]);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Option\n");
            break;
        }
    }
}