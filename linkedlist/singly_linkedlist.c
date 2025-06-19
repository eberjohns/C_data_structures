#include<stdio.h>
#include<stdlib.h>
#define DATATYPE int

typedef enum {
    LINKED_LIST_SUCCESS = 1,
    LINKED_LIST_FAILURE = -1,
    LINKED_LIST_UNDERFLOW = 0,
    LINKED_LIST_NULL = -2
} LinkedListStatus;


/*
    - create or initialise a singly linked list
    
    - push at head
    - pop at head
    - push at tail
    
    - peek at head
    - peek at tail

    - search

    - get size
    - is_empty

    - update(old_value,new_value)

    - clear or destroy

    - print all elements
*/

typedef struct Node{
    DATATYPE data;
    struct Node *next;
}Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
}SinglyLinkedList;

Node* create_new_node(DATATYPE data){
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

SinglyLinkedList* Singly_LinkedList(){
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if(list == NULL){
        fprintf(stderr,"!!!LinkedList couldn't be created!!!\n");
        exit(LINKED_LIST_FAILURE);
        // return NULL; // Return NULL if memory allocation fails
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int get_size_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    return list->size; // Return the size of the linked list
}

// Returns 1 if successful, 0 if not
int push_head_LinkedList(SinglyLinkedList* list, DATATYPE data) {
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    Node* newNode = create_new_node(data);
    if (newNode == NULL) return LINKED_LIST_FAILURE;

    newNode->next = list->head;
    list->head = newNode;

    // If the list was empty before adding this node, it's also the tail
    if (list->tail == NULL) {
        list->tail = newNode;
    }
    list->size++;
    return LINKED_LIST_SUCCESS;
}

// Returns 1 if successful, 0 if not
int push_tail_LinkedList(SinglyLinkedList* list, DATATYPE data) {
    if (list == NULL) return LINKED_LIST_NULL;

    Node* newNode = create_new_node(data);
    if (newNode == NULL) return LINKED_LIST_FAILURE;

    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
    return LINKED_LIST_SUCCESS;
}

// returns 1 if empty, 0 else
int isEmpty_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(list->head==NULL)
        return 1;
    return 0;
}

DATATYPE pop_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(isEmpty_LinkedList(list)){
        fprintf(stderr,"!!!UnderFlow!!!\n");
        return LINKED_LIST_UNDERFLOW;
    }else{
        Node* temp = list->head->next;
        DATATYPE return_value = list->head->data;
        free(list->head);
        list->head = temp;
        list->size--; // Decrement size
        if(list->head == NULL) {
            list->tail = NULL; // If the list is now empty, set tail to NULL
        }
        return return_value;
    }
}

int clear_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    while(!isEmpty_LinkedList(list)){
        pop_LinkedList(list);
    }
    return LINKED_LIST_SUCCESS;
}

int print_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(isEmpty_LinkedList(list)){
        printf("All elements: \n HEAD -> NULL\n");
        return LINKED_LIST_SUCCESS;
    }
    Node* pointer = list->head;
    printf("All elements: \n HEAD -> ");
    while(pointer!=NULL){
        printf("%d -> ",pointer->data);
        pointer = pointer->next;
    }
    printf("NULL\n Size: %d\n", list->size);
    return LINKED_LIST_SUCCESS;
}

// returns 1 if found, 0 if not found
int search_LinkedList(SinglyLinkedList* list, DATATYPE data){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(isEmpty_LinkedList(list)){
        return 0;
    }
    Node* pointer = list->head;
    while(pointer!=NULL){
        if(pointer->data == data){
            return 1; // Found
        }
        pointer = pointer->next;
    }
    return 0; // Not Found
}

// returns 1 if modified, 0 if old_value not found
int modify_LinkedList(SinglyLinkedList* list, DATATYPE old_value, DATATYPE new_value){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(isEmpty_LinkedList(list)){
        return 0; // Old value not found
    }
    Node* pointer = list->head;
    while(pointer!=NULL){
        if(pointer->data == old_value){
            pointer->data = new_value;
            return 1; // Modified successfully
        }
        pointer = pointer->next;
    }
    return 0; // Old value not found
}

DATATYPE peek_head_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(isEmpty_LinkedList(list)){
        fprintf(stderr,"!!!UnderFlow!!!\n");
        return LINKED_LIST_UNDERFLOW;
    }
    return list->head->data;
}

DATATYPE peek_tail_LinkedList(SinglyLinkedList* list){
    if (list == NULL) return LINKED_LIST_NULL; // Handle null list pointer

    if(isEmpty_LinkedList(list)){
        fprintf(stderr,"!!!UnderFlow!!!\n");
        return LINKED_LIST_UNDERFLOW;
    }
    return list->tail->data;
}

int main(){
    SinglyLinkedList* list = Singly_LinkedList();
    
    push_head_LinkedList(list,6);
    push_head_LinkedList(list,7);
    push_head_LinkedList(list,13);
    push_head_LinkedList(list,45);
    push_head_LinkedList(list,43356);
    push_head_LinkedList(list,465);
    push_head_LinkedList(list,5);
    push_head_LinkedList(list,3);
    push_tail_LinkedList(list, 100);
    
    print_LinkedList(list);

    pop_LinkedList(list);
    print_LinkedList(list);

    DATATYPE to_search = 4;
    printf(search_LinkedList(list,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    to_search = 43356;
    printf(search_LinkedList(list,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    modify_LinkedList(list, 43356, 4);
    print_LinkedList(list);

    to_search = 4;
    printf(search_LinkedList(list,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    printf("Head element: %d\n", peek_head_LinkedList(list));
    printf("Tail element: %d\n", peek_tail_LinkedList(list));

    printf(isEmpty_LinkedList(list) ? "Empty\n" : "Not Empty\n");
    clear_LinkedList(list);
    pop_LinkedList(list); // This should trigger underflow
    printf(isEmpty_LinkedList(list) ? "Empty\n" : "Not Empty\n");

    free(list); // Free the linked list structure

    return 0;
}