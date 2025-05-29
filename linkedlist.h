#ifndef LINKEDLIST_H  // Include guard to prevent multiple inclusions
#define LINKEDLIST_H

#include <stdio.h>   // For printf
#include <stdlib.h>  // For malloc, free, exit

// Constant for error reporting
#define ERROR_VALUE -1 // Or: extern const int ERROR_VALUE; and define in .c

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function Declarations (Prototypes)
struct Node* LinkedList(); // Consider if this is still needed or if NULL is used directly
struct Node* createNode(int data);
int peak(struct Node* head);
void push(struct Node** head, int data);
int pop(struct Node** head);
// For enqueue, you'll need to decide how to manage the tail.
// If sticking to your array-based head/tail management:
// void enqueue(struct Node* queue_repr[2], int data); // where queue_repr[0] is head, queue_repr[1] is tail
// Or, a more general approach:
void enqueue_general(struct Node** head, struct Node** tail, int data); // Requires passing tail explicitly
// For simplicity, let's assume you adapt the original enqueue's logic
// or create a queue struct later. For now, I'll list the original intent.
// The provided enqueue signature 'void enqueue(struct Node** head, int data)'
// assumes head and tail are adjacent in memory (e.g., an array).
// Let's list the original signature but note its specific usage context.
void enqueue(struct Node** head_and_tail_array_accessor, int data);

int isEmpty(struct Node* head);
int search(struct Node* head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* head);

#endif // LINKEDLIST_H
