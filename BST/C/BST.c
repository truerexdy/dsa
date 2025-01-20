#include <stdio.h> //For stdin and stdout
#include <stdlib.h> //For DMA and exit(0)

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;
/*This is a structure which has three fields, data, left node and right node.
data is int and the rest two are pointers to a struct node*/

node* insert(int data, node* root){
    /*Insert function has two parameters data-the actual integer data that should be inserted into the tree
    and the pointer to the root node*/
    if(!root){
        // If the tree is empty i.e. root node is NULL we don't have to check anything, just insert to root
        node* temp = (node*)malloc(sizeof(node)); //allocate memory
        temp->left = NULL; //init right and left node to NULL
        temp->right=NULL;
        temp->data = data; //insert the data into the node
        return temp; //return the pointer to the allocated memory
    }
    if(root->data == data){
        /* If data in a node is equal to the data we are trying to insert, that means the value already
        exists in the tree so no need to insert*/
        printf("Value Already Exists\n");
    }
    else if(root->data<data){
        /*If the value of the data to be inserted is greater than the value of the data in the root node
        then the new data should be inserted in the right sub-tree*/
        root->right=insert(data, root->right); //insert() is recursively called for the right sub-tree
    }
    else{
        /*If the above two condetions fail then the value to be inserted is less than the value in the node
        so we must insert that data into the left sub-tree*/
        root->left=insert(data, root->left); //again recursive call for left sub-tree
    }
    return root; // at last return the updated root node pointer to the main
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