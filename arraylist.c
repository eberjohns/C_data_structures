#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *data; // Pointer to the array that holds the elements
    int size;  // Current size of the array
    int capacity; // Maximum capacity of the array
}ArrayList;

ArrayList create_ArrayList(int capacity) {
    ArrayList arraylist;
    arraylist.data = (int *)malloc(capacity * sizeof(int));
    if(arraylist.data == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    arraylist.size = 0;
    arraylist.capacity = capacity;
    return arraylist;
}

void insert_ArrayList(ArrayList *arraylist, int index, int value) {
    if(index < 0 || index > arraylist->size) {
        printf("Index out of bounds\n");
        return;
    }
    if(arraylist->size >= arraylist->capacity) {
        // Resize the array to double previous size if capacity is reached
        arraylist->capacity *= 2;
        arraylist->data = (int *)realloc(arraylist->data, arraylist->capacity * sizeof(int));
        if(arraylist->data == NULL) {
            printf("Memory allocation failed\n");
            exit(1); // Exit if memory allocation fails
        }
    }
    // Shift elements to the right
    for(int i = arraylist->size; i > index; i--) {
        arraylist->data[i] = arraylist->data[i - 1];
    }
    // Insert the new value
    arraylist->data[index] = value;
    arraylist->size++;
}

int indexOf_ArrayList(ArrayList *arraylist, int value) {
    for(int i = 0; i < arraylist->size; i++) {
        if(arraylist->data[i] == value) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

void deleteAt_ArrayList(ArrayList *arraylist, int index) {
    if(index < 0 || index >= arraylist->size) {
        printf("Index out of bounds\n");
        return;
    }
    // Shift elements to the left
    for(int i = index; i < arraylist->size - 1; i++) {
        arraylist->data[i] = arraylist->data[i + 1];
    }
    arraylist->size--;
}

void append_ArrayList(ArrayList *arraylist, int value) {
    if(arraylist->size >= arraylist->capacity) {
        // Resize the array to double previous size if capacity is reached
        arraylist->capacity *= 2;
        arraylist->data = (int *)realloc(arraylist->data, arraylist->capacity * sizeof(int));
        if(arraylist->data == NULL) {
            printf("Memory allocation failed\n");
            exit(1); // Exit if memory allocation fails
        }
    }
    // Append the new value
    arraylist->data[arraylist->size] = value;
    arraylist->size++;
}

void removeLast_ArrayList(ArrayList *arraylist) {
    if(arraylist->size > 0) {
        arraylist->size--; // Decrease size to remove the last element
    } else {
        printf("ArrayList is empty, nothing to remove\n");
    }
}

void clear_ArrayList(ArrayList *arraylist) {
    arraylist->size = 0; // Reset size to clear the ArrayList
}

int main(){
    //static array declaration
    int arr[4] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    //array elements
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    //dynamic array declaration
    int sizeDynamic = 4;
    int *dynamicArr = (int *)malloc(sizeDynamic * sizeof(int));
    if(dynamicArr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
    dynamicArr[0] = 5;
    dynamicArr[1] = 6;
    dynamicArr[2] = 7;
    dynamicArr[3] = 8;

    //dynamic array elements
    for(int i = 0; i < sizeDynamic; i++){
        printf("%d ", dynamicArr[i]);
    }
    // Free dynamically allocated memory
    free(dynamicArr);

    printf("\n");
    //arraylist
    /* 
    arraylist opeations:
    create, append, insert, indexof, deleteAt, removeLast, size, clear
    */
    ArrayList arraylist = create_ArrayList(4);
    insert_ArrayList(&arraylist, 0, 9); // arraylist.data[0] = 9;
    insert_ArrayList(&arraylist, 1, 10); // arraylist.data[1] = 10;
    insert_ArrayList(&arraylist, 2, 11); // arraylist.data[2] = 11;
    insert_ArrayList(&arraylist, 3, 12); // arraylist.data[3] = 12;
    insert_ArrayList(&arraylist, 4, 13); // arraylist.data[4] = 13;
    insert_ArrayList(&arraylist, 2, 14); // Insert 14 at index 2
    // Print ArrayList elements
    for(int i = 0; i < arraylist.size; i++) {
        printf("%d ", arraylist.data[i]);
    }
    append_ArrayList(&arraylist, 15); // Append 15 to the ArrayList
    // Print ArrayList elements after appending
    printf("\nAfter appending 15: ");
    for(int i = 0; i < arraylist.size; i++) {
        printf("%d ", arraylist.data[i]);
    }
    printf("\nIndex of 11: %d\n", indexOf_ArrayList(&arraylist, 11)); // Should return index of 11
    deleteAt_ArrayList(&arraylist, 2); // Delete element at index 2
    // Print ArrayList elements after deletion
    printf("After deleting element at index 2: ");
    for(int i = 0; i < arraylist.size; i++) {
        printf("%d ", arraylist.data[i]);
    }
    removeLast_ArrayList(&arraylist); // Remove the last element
    // Print ArrayList elements after removing the last element
    printf("\nAfter removing the last element: ");
    for(int i = 0; i < arraylist.size; i++) {
        printf("%d ", arraylist.data[i]);
    }

    clear_ArrayList(&arraylist); // Clear the ArrayList
    printf("\nAfter clearing the ArrayList, size: %d\n", arraylist.size); // Should be 0
    // Print ArrayList elements after clearing
    for(int i = 0; i < arraylist.size; i++) {
        printf("%d ", arraylist.data[i]);
    }

    // Free the memory allocated for the ArrayList
    free(arraylist.data);
    
    return 0;
}