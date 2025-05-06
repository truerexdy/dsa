#include <stdio.h> //For stdin and stdout
#include <stdlib.h> //For DMA and exit(0)

typedef struct node{
    int data;
    struct node* next;
}node;

node* cat(node* sll1, node* sll2){
    if(!sll1 || !sll2){
        if(sll1){
            return sll1;
        }
        else if(sll2){
            return sll2;
        }
        else{
            printf("Both the lists are empty!\n");
            return NULL;
        }
    }
    node* curr = sll1;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = sll2;
    return sll1;
}