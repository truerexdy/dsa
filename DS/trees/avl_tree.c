#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void updateHeight(struct node* n) {
    if (n != NULL) {
        n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }
}

int getBalanceFactor(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node* leftRotate(struct node* y) {
    struct node* x = y->right;
    struct node* T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct node* rightRotate(struct node* x) {
    struct node* y = x->left;
    struct node* T2 = y->right;

    y->right = x;
    x->left = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

struct node* insert_recursive(struct node* node, int key) {
    if (node == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key) {
        node->left = insert_recursive(node->left, key);
    } else if (key > node->key) {
        node->right = insert_recursive(node->right, key);
    } else {
        printf("Warning: Duplicate key %d not inserted.\n", key);
        return node;
    }

    updateHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void insert(struct node** root_ref, int key) {
    *root_ref = insert_recursive(*root_ref, key);
}

struct queue_node {
    struct node* tree_node;
    struct queue_node* next;
};

struct queue {
    struct queue_node *front, *rear;
};

struct queue_node* newQueueNode(struct node* tree_node) {
    struct queue_node* temp = (struct queue_node*)malloc(sizeof(struct queue_node));
    if (temp == NULL) {
        perror("Memory allocation failed for queue node");
        exit(EXIT_FAILURE);
    }
    temp->tree_node = tree_node;
    temp->next = NULL;
    return temp;
}

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    if (q == NULL) {
        perror("Memory allocation failed for queue");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue* q, struct node* tree_node) {
    struct queue_node* temp = newQueueNode(tree_node);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

struct node* dequeue(struct queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    struct queue_node* temp = q->front;
    struct node* tree_node = temp->tree_node;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return tree_node;
}

bool isQueueEmpty(struct queue* q) {
    return q->front == NULL;
}

void freeQueue(struct queue* q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

void display_level_order(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct queue* q = createQueue();
    enqueue(q, root);

    printf("AVL tree (level by level):\n");

    while (!isQueueEmpty(q)) {
        int levelSize = 0;
        struct queue_node* current = q->front;
        while(current != NULL) {
            levelSize++;
            current = current->next;
        }

        for (int i = 0; i < levelSize; ++i) {
            struct node* currentNode = dequeue(q);

            if (currentNode != NULL) {
                printf("%d ", currentNode->key);

                if (currentNode->left != NULL) {
                    enqueue(q, currentNode->left);
                }

                if (currentNode->right != NULL) {
                    enqueue(q, currentNode->right);
                }
            }
        }
        printf("\n");
    }

    freeQueue(q);
}

void delete_recursive(struct node* node) {
    if (node == NULL) {
        return;
    }
    delete_recursive(node->left);
    delete_recursive(node->right);
    free(node);
}

int main() {
    struct node* root = NULL;

    int choice;
    int key;

    do {
        printf("\nAVL Tree Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Display Tree (Level by Level)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                if (scanf("%d", &key) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n');
                } else {
                    while (getchar() != '\n');
                    insert(&root, key);
                    printf("%d inserted.\n", key);
                }
                break;
            case 2:
                display_level_order(root);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    delete_recursive(root);
    root = NULL;

    return 0;
}