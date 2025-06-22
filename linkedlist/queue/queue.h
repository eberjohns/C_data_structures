#include "singly_linkedlist.h"
#ifndef QUEUE_H  // Include guard to prevent multiple inclusions
#define QUEUE_H

/*
enqueue()
dequeue()
front()
isEmpty()
*/

SinglyLinkedList* (*Queue)() = Singly_LinkedList;

int isEmpty(SinglyLinkedList* list) {
    return list->size == 0;
}

int (*enqueue)(SinglyLinkedList*, DATATYPE) = push_tail_LinkedList;

DATATYPE (*dequeue)(SinglyLinkedList*) = pop_LinkedList;

DATATYPE (*front)(SinglyLinkedList*) = peek_head_LinkedList;

int size(SinglyLinkedList* list) {
    return list->size;
}

int (*clear)(SinglyLinkedList*) = clear_LinkedList;

#endif // QUEUE_H