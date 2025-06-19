#include<stdio.h>
#include<stdlib.h>
#define LINKED_LIST_FAILURE -1
#define LIST_UNDERFLOW 0

/*
    - add at head - for stack :push
    - remove at head - for stack and queue :pop deletes and returns
    add at tail - for queue :pushTail

    - peak at head
    peak at tail

    - search for a number

    - is_empty
    is_full

    - update(old_value,new_value)

    - clear and destroy same here

    - print all elements
*/

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* create_new_node(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        // fprintf(stderr,"!!!Node couldn't be created!!!");
        // exit(LINKED_LIST_FAILURE);
        return NULL; // Return NULL if memory allocation fails
    }
    node->data = data;
    node->next = NULL;

    return node;
}

// returns 1 if linkedlist created successfully, 0 if not
int push_LinkedList(Node** linkedlist, int data){
    if (*linkedlist == NULL){
        *linkedlist = create_new_node(data);
        if (*linkedlist == NULL) return 0; // Return 0 if memory allocation fails
    }else{
        Node* temp = create_new_node(data);
        if (temp == NULL) return 0; // Return 0 if memory allocation fails
        temp->next = *linkedlist;
        *linkedlist = temp;
    }
    return 1; // Successfully pushed
}

// returns 1 if empty, 0 else
int isEmpty_LinkedList(Node** linkedlist){
    if(*linkedlist==NULL)
        return 1;
    return 0;
}

int pop_LinkedList(Node** linkedlist){
    if(isEmpty_LinkedList(linkedlist)){
        fprintf(stderr,"!!!UnderFlow!!!\n");
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
        printf("All elements: \n HEAD -> NULL\n");
        return;
    }
    Node* pointer = *linkedlist;
    printf("All elements: \n HEAD -> ");
    while(pointer->next!=NULL){
        printf("%d -> ",pointer->data);
        pointer = pointer->next;
    }printf("%d -> NULL\n",pointer->data);
}

// returns 1 if found, 0 if not found
int search_LinkedList(Node** linkedlist, int data){
    if(isEmpty_LinkedList(linkedlist)){
        return 0;
    }
    Node* pointer = *linkedlist;
    while(pointer->next!=NULL){
        if(pointer->data == data){
            return 1; // Found
        }
        pointer = pointer->next;
    }
    return pointer->data == data ? 1 : 0; // Check the last node
}

// returns 1 if modified, 0 if old_value not found
int modify_LinkedList(Node** linkedlist, int old_value, int new_value){
    if(isEmpty_LinkedList(linkedlist)){
        return 0; // Old value not found
    }
    Node* pointer = *linkedlist;
    while(pointer->next!=NULL){
        if(pointer->data == old_value){
            pointer->data = new_value;
            return 1; // Modified successfully
        }
        pointer = pointer->next;
    }
    // Check the last node
    if(pointer->data == old_value){
        pointer->data = new_value;
        return 1; // Modified successfully
    }
    return 0; // Old value not found
}

int peak_head_LinkedList(Node** linkedlist){
    if(isEmpty_LinkedList(linkedlist)){
        fprintf(stderr,"!!!UnderFlow!!!\n");
        return LIST_UNDERFLOW;
    }
    return (*linkedlist)->data;
}

int main(){
    Node* linkedlist = NULL;//create_LinkedList();
    
    push_LinkedList(&linkedlist,6);
    push_LinkedList(&linkedlist,7);
    push_LinkedList(&linkedlist,13);
    push_LinkedList(&linkedlist,45);
    push_LinkedList(&linkedlist,43356);
    push_LinkedList(&linkedlist,465);
    push_LinkedList(&linkedlist,5);
    push_LinkedList(&linkedlist,3);
    
    print_LinkedList(&linkedlist);

    pop_LinkedList(&linkedlist);
    print_LinkedList(&linkedlist);

    int to_search = 4;
    printf(search_LinkedList(&linkedlist,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    to_search = 43356;
    printf(search_LinkedList(&linkedlist,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    modify_LinkedList(&linkedlist, 43356, 4);
    print_LinkedList(&linkedlist);

    to_search = 4;
    printf(search_LinkedList(&linkedlist,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    printf("Head element: %d\n", peak_head_LinkedList(&linkedlist));

    printf(isEmpty_LinkedList(&linkedlist) ? "Empty\n" : "Not Empty\n");
    clear_LinkedList(&linkedlist);
    pop_LinkedList(&linkedlist); // This should trigger underflow
    printf(isEmpty_LinkedList(&linkedlist) ? "Empty\n" : "Not Empty\n");

    return 0;
}