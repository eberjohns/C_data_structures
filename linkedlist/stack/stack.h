#include "singly_linkedlist.h"
#ifndef STACK_H  // Include guard to prevent multiple inclusions
#define STACK_H

/*
push()
pop()
peek()
isEmpty()
*/

SinglyLinkedList* Stack() {
    return Singly_LinkedList();
}

int isEmpty(SinglyLinkedList* list) {
    return isEmpty_LinkedList(list);
}

DATATYPE pop(SinglyLinkedList* list) {
    return pop_LinkedList(list);
}

DATATYPE peek(SinglyLinkedList* list) {
    return peek_head_LinkedList(list);
}

int push(SinglyLinkedList* list, DATATYPE data) {
    return push_head_LinkedList(list, data);
}

int clear(SinglyLinkedList* list) {
    return clear_LinkedList(list);
}

#endif // STACK_H