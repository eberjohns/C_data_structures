#include "stack.h"

int main() {
    SinglyLinkedList* stack = Stack();
    
    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    // Peek at the top element
    printf("Top element: %d\n", peek(stack));
    
    // Pop elements from the stack
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    
    // Check if the stack is empty
    printf(isEmpty(stack) ? "Stack is empty\n" : "Stack is not empty\n");
    
    // Clear the stack
    clear(stack);
    
    // Check if the stack is empty after clearing
    printf(isEmpty(stack) ? "Stack is empty after clearing\n" : "Stack is not empty after clearing\n");
    
    free(stack); // Free the stack structure
    
    return 0;
}

// Compile this code with the following command:
// gcc stack_example.c singly_linkedlist.c -o stack_example