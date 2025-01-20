#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* insert(int data, node* root){
    if(!root){
        node* temp = (node*)malloc(sizeof(node));
        return temp;
    }
    if(root->data == data){
        printf("Value Already Exists\n");
        return NULL;
    }
    else if(root->data<data){
        root->right=insert(data, root->right);
    }
    else{
        root->left=insert(data, root->left);
    }
}

void inorder(node* root){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root){
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main(){
    node* root = NULL;
    while(1){
        printf("1.Insert\n2.In-order\n3.Pre-order\n4.Post-order\n5.Exit\n");
        int userinput; scanf("%d", &userinput);
        switch (userinput){
            case 1:
            printf("Enter the number\n");
            scanf("%d", &userinput);
            root = insert(userinput, root);
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Enter a valid option");
        }
    }
    return 0;
}