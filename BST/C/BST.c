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
        temp->left = NULL;
        temp->right=NULL;
        temp->data = data;
        return temp;
    }
    if(root->data == data){
        printf("Value Already Exists\n");
    }
    else if(root->data<data){
        root->right=insert(data, root->right);
    }
    else{
        root->left=insert(data, root->left);
    }
    return root;
}

void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root){
    if(!root){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(!root){
        return;
    }
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
            printf("\n");
            break;
            case 3:
            preorder(root);
            printf("\n");
            break;
            case 4:
            postorder(root);
            printf("\n");
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