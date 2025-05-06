#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {operator, operand} nodetype;

typedef struct node{
    nodetype type;
    union{
        int operand;
        char operator;
    } data;
    struct node* left;
    struct node* right;
}node;

int evaluate(node* root){
    if(!root){
        return 0;
    }
    if(root->type == operand){
        return root->data.operand;
    }
    else{
        switch (root->data.operator){
            case '^':
            return pow(evaluate(root->left),evaluate(root->right));
            break;
            case '*':
            return evaluate(root->left)*evaluate(root->right);
            break;
            case '/':
            return evaluate(root->left)/evaluate(root->right);
            break;
            case '%':
            return evaluate(root->left)%evaluate(root->right);
            break;
            case '+':
            return evaluate(root->left)+evaluate(root->right);
            break;
            case '-':
            return evaluate(root->left)-evaluate(root->right);
            break;
        }
    }
    return 0;
}