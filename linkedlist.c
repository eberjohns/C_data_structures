#include "linkedlist.h" // Include your header file

// If ERROR_VALUE was declared with 'extern const int' in .h:
// const int ERROR_VALUE = -1;

struct Node* LinkedList() {
    return NULL;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Or return NULL and let caller handle
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int peak(struct Node* head) {
    if (head == NULL) {
        // printf("List is empty in peak\n"); // Consider if print is desired in library code
        return ERROR_VALUE;
    }
    return head->data;
}

void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return; // If createNode can return NULL
    newNode->next = *head;
    *head = newNode;
}

int pop(struct Node** head) {
    if (*head == NULL) {
        // printf("List is empty in pop\n");
        return ERROR_VALUE;
    }
    struct Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Implementation for the original enqueue assuming 'head_and_tail_array_accessor'
// points to the first element of a two-element array [head_ptr, tail_ptr]
void enqueue(struct Node** head_and_tail_array_accessor, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;

    struct Node** head_ptr_loc = head_and_tail_array_accessor;
    struct Node** tail_ptr_loc = head_and_tail_array_accessor + 1;

    if (*tail_ptr_loc == NULL) { // If queue is empty (tail pointer is NULL)
        *head_ptr_loc = newNode;
        *tail_ptr_loc = newNode;
    } else {
        (*tail_ptr_loc)->next = newNode;
        *tail_ptr_loc = newNode;
    }
}

// A more general enqueue if you manage head and tail pointers separately:
/*
void enqueue_general(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    if (*tail == NULL) { // If queue is empty
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
*/

int isEmpty(struct Node* head) {
    return head == NULL;
}

int search(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // found
        }
        current = current->next;
    }
    return 0; // not found
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        // printf("List is empty in deleteNode\n");
        return;
    }
    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // printf("Node with data %d not found in deleteNode\n", data);
        return; // Node not found
    }

    if (previous == NULL) {
        *head = current->next; // Node to delete is the head
    } else {
        previous->next = current->next; // Bypass the node to delete
    }
    free(current);
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
