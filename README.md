# C Data Structures [Linked List,Stack,Queue]
This repository contains a C implementation of a singly linked list, along with functions to perform common operations, including stack (LIFO) and queue (FIFO) behaviors.

🌟 **Features**
- **Node Creation:** Dynamically create new list nodes.

- **Stack Operations:**

  - `push()`: Add an element to the top of the stack (front of the list).

  - `pop()`: Remove and return the element from the top of the stack.

  - `peak()`: View the top element without removing it.

- Queue Operations:

  - `enqueue()`: Add an element to the end of the queue.

  - Uses `pop()` for dequeue (removing from the front of the list).

  - Note: The provided `enqueue` function has a specific implementation detail for managing the tail pointer (see "Important Notes" below).

- General List Operations:

  - `isEmpty()`: Check if the list is empty.

  - `search()`: Find if an element exists in the list.

  - `deleteNode()`: Remove a node with a specific value from the list.

  - `printList()`: Display the contents of the list.


📂 File Structure
- `linkedlist.h`: The header file. It contains:

  - The definition of the `struct Node`.

  - The `ERROR_VALUE` constant.

  - Function prototypes for all linked list operations.

- `linkedlist.c`: The source file. It contains:

  - The actual C implementation of all functions declared in `linkedlist.h`.

🚀 **How to Use (Local Compilation)**
**Include the Header:**
1. In your C program where you want to use the linked list, include the header file:
   ```C
    #include "linkedlist.h"
    #include <stdio.h> // For printf in your main program

    int main() {
        // Your code here
        return 0;
    }
   ```
2. Compile:
   When compiling, you need to include both your program's .c file and linkedlist.c:
   ```bash
      gcc your_program_name.c linkedlist.c -o your_program_name
   ```
   For example, if your main file is main.c:
    ```bash
       gcc main.c linkedlist.c -o main
       ./main
    ```
3. Example Usage:
   ```C
      #include "linkedlist.h"
      #include <stdio.h>
      
      int main() {
          // Stack Example
          printf("--- Stack Example ---\n");
          struct Node* myStack = NULL; // Or LinkedList();
          push(&myStack, 10);
          push(&myStack, 20);
          push(&myStack, 30);
          printf("Stack: ");
          printList(myStack); // Output: 30 -> 20 -> 10 -> NULL
          printf("Popped: %d\n", pop(&myStack)); // Output: Popped: 30
          printf("Stack after pop: ");
          printList(myStack); // Output: 20 -> 10 -> NULL
          printf("Peak: %d\n", peak(myStack)); // Output: Peak: 20
      
          // Queue Example (using the specific enqueue implementation)
          printf("\n--- Queue Example ---\n");
          // queue_elements[0] is head, queue_elements[1] is tail
          struct Node* queue_elements[2] = {NULL, NULL};
      
          enqueue(queue_elements, 5);
          enqueue(queue_elements, 15);
          enqueue(queue_elements, 25);
          printf("Queue: ");
          printList(queue_elements[0]); // Output: 5 -> 15 -> 25 -> NULL
          printf("Dequeued (pop from front): %d\n", pop(&queue_elements[0])); // Output: Dequeued: 5
          // Important: After popping the last element that was also the tail,
          // queue_elements[1] (tail pointer) might need manual resetting to NULL
          // if you continue to use it without further enqueues that reset it.
          // The current pop doesn't update the separate tail pointer.
          if (isEmpty(queue_elements[0])) {
              queue_elements[1] = NULL; // Manually reset tail if queue becomes empty
          }
          printf("Queue after dequeue: ");
          printList(queue_elements[0]); // Output: 15 -> 25 -> NULL
      
          // Clean up memory (example for stack, similar for queue head)
          while(!isEmpty(myStack)) {
              pop(&myStack);
          }
          while(!isEmpty(queue_elements[0])) {
              pop(&queue_elements[0]);
          }
          printf("\nStack and Queue cleared.\n");
      
          return 0;
      }
   ```
📝 **Function Signatures**
(Refer to `linkedlist.h` for complete details)
```
  struct Node* createNode(int data);
  int peak(struct Node* head);
  void push(struct Node** head, int data);
  int pop(struct Node** head);
  void enqueue(struct Node** head_and_tail_array_accessor, int data);
  // Alternative: void enqueue_general(struct Node** head, struct Node** tail, int data);
  int isEmpty(struct Node* head);
  int search(struct Node* head, int data);
  void deleteNode(struct Node** head, int data);
  void printList(struct Node* head);
```
⚠️ **Important Notes on `enqueue`**

The current `enqueue` function in `linkedlist.c`:
```
  void enqueue(struct Node** head_and_tail_array_accessor, int data);
```
expects `head_and_tail_array_accessor` to be a pointer to the first element of a two-element array of `struct Node* `. The first element (`*head_and_tail_array_accessor`) is treated as the list's head pointer, and the second element (`*(head_and_tail_array_accessor + 1)`) is treated as the list's tail pointer.

Example:
```
  struct Node* queue_ptrs[2] = {NULL, NULL}; // queue_ptrs[0] for head, queue_ptrs[1] for tail
  enqueue(queue_ptrs, 100);
```
This allows  `enqueue` to maintain an O(1) time complexity by directly updating the tail.

For a more general queue implementation, you might consider:

1. Creating a `struct Queue` that encapsulates both `head` and `tail` pointers.

2. Using a function like `enqueue_general(struct Node** head, struct Node** tail, int data)` where you pass both head and tail pointers explicitly.

🧩 **Usage with LeetCode / Online Judges**
For platforms like LeetCode, you generally cannot directly `#include` custom files from a repository. Instead, you will need to:

1. Adapt the `struct Node` definition if it differs (e.g., `val` instead of `data`).

2. Copy and paste the required helper functions (e.g., `createNode`, `push`, specific list manipulation logic) directly into the solution editor provided by the platform.

This repository serves as a good personal library for understanding and practicing these data structures locally.

🌱 **Future Enhancements (Ideas)**
- Implement a `freeList()` function to deallocate all nodes in a list.

- Add support for doubly linked lists.

- Implement a circular linked list.

- More robust error handling and reporting.

- Generic data types (e.g., using `void*` and function pointers for comparison/printing).


## Feel free to clone, use, and contribute!❤🐱‍🏍✨
