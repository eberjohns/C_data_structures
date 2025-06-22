#include "singly_linkedlist.h"
#ifndef STACK_H  // Include guard to prevent multiple inclusions
#define STACK_H

/*
push()
pop()
peek()
isEmpty()
*/

SinglyLinkedList* (*Stack)() = Singly_LinkedList;

int isEmpty(SinglyLinkedList* list) {
    return list->size == 0;
}

int (*push)(SinglyLinkedList*, DATATYPE) = push_head_LinkedList;

DATATYPE (*pop)(SinglyLinkedList*) = pop_LinkedList;

DATATYPE (*peek)(SinglyLinkedList*) = peek_head_LinkedList;

int size(SinglyLinkedList* list) {
    return list->size;
}

int (*clear)(SinglyLinkedList*) = clear_LinkedList;

#endif // STACK_H