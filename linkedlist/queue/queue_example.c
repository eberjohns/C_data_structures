#include "queue.h"

int main() {
    SinglyLinkedList* queue = Queue(); // Create a new queue using the linked list

    // Enqueue elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Display the front element
    printf("Front element: %d\n", front(queue));

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Check if the queue is empty
    printf(isEmpty(queue) ? "Queue is empty\n" : "Queue is not empty\n");

    // Clear the queue
    clear(queue);

    // Check if the queue is empty after clearing
    printf(isEmpty(queue) ? "Queue is empty after clearing\n" : "Queue is not empty after clearing\n");

    free(queue); // Free the queue structure

    return 0;
}


// Compile this code with the following command:
// gcc -I.. queue_example.c ../singly_linkedlist.c -o queue_test
