#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if(!new_node){
        printf("\nInsufficient Memory\n");
        return NULL;
    }
    return new_node;
}

void free_list(node* head) {
    while (head) {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

node* insert_at_end(node* head, node* new_node){
    if(!head){
        return new_node;
    }
    if(!new_node){
        printf("\nNew node is null.\n");
        return head;
    }
    node* curr = head;
    while(curr->next){
        curr=curr->next;
    }
    curr->next = new_node;
    return head;
}

node* insert_at_start(node* head, node* new_node){
    if(!head){
        return new_node;
    }
    if(!new_node){
        printf("\nNew node is null.\n");
        return head;
    }
    new_node->next = head;
    head=new_node;
    return head;
}

node* sorted_insert(node* sorted_head, node* new_node){
    if(!new_node){
        printf("\nNew node null\n");
        return sorted_head;
    }
    if(!sorted_head){
        printf("\nSorted head null\n");
        return new_node;
    }
    node* temp = sorted_head;
    if(sorted_head->data>new_node->data){
        sorted_head = insert_at_start(sorted_head, new_node);
        return sorted_head;
    }
    while(temp->data<new_node->data && temp->next){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return sorted_head;
}

node* sort_list(node* head){
    if(!head){
        printf("\nEmpty list, nothing to sort.\n");
        return NULL;
    }
    node* sorted_list = NULL;
    node* current = head;
    while(current){
        node* temp = current->next;
        current->next = NULL;
        sorted_list = sorted_insert(sorted_list, current);
        current = temp;
    }
    return sorted_list;
}

void display(node* head){
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(head){
        printf("%d ", head->data);
        head=head->next;
    }
}

int main(){
    node* head = NULL;
    while(1){
        printf("\n1.Insert at end\n2.Insert at start\n3.Sort\n4.Display\n5.Exit\n");
        int uin;
        scanf("%d", &uin);
        switch(uin){
            case 1:
            printf("Enter the number:\n");
            scanf("%d", &uin);
            head = insert_at_end(head,create_node(uin));
            break;
            case 2:
            printf("Enter the number:\n");
            scanf("%d", &uin);
            head = insert_at_start(head,create_node(uin));
            break;
            case 3:
            head = sort_list(head);
            break;
            case 4:
            display(head);
            break;
            case 5:
            free_list(head);
            exit(0);
        }
    }
}