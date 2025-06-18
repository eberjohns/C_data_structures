#include<stdio.h>
#include<stdlib.h>
#define LINKED_LIST_FAILURE -1
#define LIST_UNDERFLOW 0

/*
    add at head - for stack :push
    remove at head - for stack and queue :pop deletes and returns
    add at tail - for queue :pushTail

    peak at head
    peak at tail

    search for a number

    is_empty
    is_full

    update(old_value,new_value)

    clear and destroy same here
*/

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* create_new_node(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        fprintf(stderr,"!!!Node couldn't be created!!!");
        exit(LINKED_LIST_FAILURE);
    }
    node->data = data;
    node->next = NULL;

    return node;
}

void push_LinkedList(Node** linkedlist, int data){
    if (*linkedlist == NULL){
        *linkedlist = create_new_node(data);
    }else{
        Node* temp = create_new_node(data);
        temp->next = *linkedlist;
        *linkedlist = temp;
    }
}

// 1 if empty 0 if not
int isEmpty_LinkedList(Node** linkedlist){
    if(*linkedlist==NULL)
        return 1;
    return 0;
}

int pop_LinkedList(Node** linkedlist){
    if(isEmpty_LinkedList(linkedlist)){
        fprintf(stderr,"!!!UnderFlow!!!");
        return LIST_UNDERFLOW;
    }else{
        Node* temp = (*linkedlist)->next;
        int return_value = (*linkedlist)->data;
        free(*linkedlist);
        *linkedlist = temp;
        return return_value;
    }
}

void clear_LinkedList(Node** linkedlist){
    while(!isEmpty_LinkedList(linkedlist)){
        pop_LinkedList(linkedlist);
    }
}

void print_LinkedList(Node** linkedlist){
    if(isEmpty_LinkedList(linkedlist)){
        printf("Nothing to print!!!\n");
        return;
    }
    Node* pointer = *linkedlist;
    printf("All elements: ");
    while(pointer->next!=NULL){
        printf("%d  ",pointer->data);
        pointer = pointer->next;
    }printf("%d\n",pointer->data);
}

int main(){
    Node* linkedlist = NULL;//create_LinkedList();

    push_LinkedList(&linkedlist,5);
    
    print_LinkedList(&linkedlist);

    push_LinkedList(&linkedlist,6);
    push_LinkedList(&linkedlist,7);

    print_LinkedList(&linkedlist);

    pop_LinkedList(&linkedlist);
    print_LinkedList(&linkedlist);
    
    pop_LinkedList(&linkedlist);
    print_LinkedList(&linkedlist);
    
    clear_LinkedList(&linkedlist);

    print_LinkedList(&linkedlist);

    push_LinkedList(&linkedlist,6);
    push_LinkedList(&linkedlist,7);
    push_LinkedList(&linkedlist,13);
    push_LinkedList(&linkedlist,45);
    push_LinkedList(&linkedlist,43356);
    push_LinkedList(&linkedlist,465);
    push_LinkedList(&linkedlist,5);
    push_LinkedList(&linkedlist,3);
    print_LinkedList(&linkedlist);

    printf(isEmpty_LinkedList(&linkedlist) ? "Empty\n" : "Not Empty\n");
    clear_LinkedList(&linkedlist);
    printf(isEmpty_LinkedList(&linkedlist) ? "Empty\n" : "Not Empty\n");


    return 0;
}