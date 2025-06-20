#ifndef SINGLY_LINKEDLIST_H  // Include guard to prevent multiple inclusions
#define SINGLY_LINKEDLIST_H

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

// Function Declarations (Prototypes)
Node* create_new_node(DATATYPE data);
SinglyLinkedList* Singly_LinkedList();
int get_size_LinkedList(SinglyLinkedList* list);
int push_head_LinkedList(SinglyLinkedList* list, DATATYPE data);
int push_tail_LinkedList(SinglyLinkedList* list, DATATYPE data);
int isEmpty_LinkedList(SinglyLinkedList* list);
DATATYPE pop_LinkedList(SinglyLinkedList* list);
int clear_LinkedList(SinglyLinkedList* list);
int print_LinkedList(SinglyLinkedList* list);
int search_LinkedList(SinglyLinkedList* list, DATATYPE data);
int modify_LinkedList(SinglyLinkedList* list, DATATYPE old_value, DATATYPE new_value);
DATATYPE peek_head_LinkedList(SinglyLinkedList* list);
DATATYPE peek_tail_LinkedList(SinglyLinkedList* list);

#endif // SINGLY_LINKEDLIST_H