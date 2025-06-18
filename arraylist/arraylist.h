#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h> // For size_t
#include <stdlib.h> // For malloc, realloc, free

// Define error codes for function returns
#define ARRAYLIST_SUCCESS         0
#define ARRAYLIST_FAILURE        -1
#define ARRAYLIST_OUT_OF_BOUNDS  -2
#define ARRAYLIST_EMPTY_ERROR    -3 // For operations on empty list

// --- ArrayList Structure Definition ---
typedef struct {
    int *data;      // Pointer to the array that holds the elements
    int size;       // Current number of elements in the array
    int capacity;   // Maximum allocated capacity of the array
} ArrayList;

// --- Function Prototypes ---

/**
 * @brief Creates a new ArrayList with a specified initial capacity.
 * @param initial_capacity The initial memory capacity for the list.
 * @return An ArrayList struct. Check list.data == NULL to detect allocation failure.
 */
ArrayList create_ArrayList(int initial_capacity);

/**
 * @brief Appends a value to the end of the ArrayList.
 * @param list Pointer to the ArrayList.
 * @param value The integer value to append.
 * @return ARRAYLIST_SUCCESS on success, ARRAYLIST_FAILURE if memory reallocation fails.
 */
int append_ArrayList(ArrayList *list, int value);

/**
 * @brief Inserts a value at a specified index in the ArrayList.
 * Elements from the index onwards are shifted to the right.
 * @param list Pointer to the ArrayList.
 * @param index The position where the value should be inserted.
 * @param value The integer value to insert.
 * @return ARRAYLIST_SUCCESS on success, ARRAYLIST_FAILURE if memory reallocation fails,
 * ARRAYLIST_OUT_OF_BOUNDS if the index is invalid.
 */
int insert_ArrayList(ArrayList *list, int index, int value);

/**
 * @brief Finds the first occurrence of a value in the ArrayList.
 * @param list Pointer to the ArrayList.
 * @param value The integer value to search for.
 * @return The index of the value if found, -1 otherwise.
 */
int indexOf_ArrayList(const ArrayList *list, int value);

/**
 * @brief Deletes the element at a specified index in the ArrayList.
 * Elements after the index are shifted to the left.
 * @param list Pointer to the ArrayList.
 * @param index The position of the element to delete.
 * @return ARRAYLIST_SUCCESS on success, ARRAYLIST_OUT_OF_BOUNDS if the index is invalid.
 */
int deleteAt_ArrayList(ArrayList *list, int index);

/**
 * @brief Removes the last element from the ArrayList.
 * @param list Pointer to the ArrayList.
 * @return ARRAYLIST_SUCCESS on success, ARRAYLIST_EMPTY_ERROR if the list is already empty.
 */
int removeLast_ArrayList(ArrayList *list);

/**
 * @brief Clears all elements from the ArrayList by resetting its size to 0.
 * Does not free allocated memory, allowing for reuse.
 * @param list Pointer to the ArrayList.
 */
void clear_ArrayList(ArrayList *list);

/**
 * @brief Frees all memory allocated for the ArrayList's data.
 * Resets size and capacity to 0 and data to NULL.
 * @param list Pointer to the ArrayList.
 */
void destroy_ArrayList(ArrayList *list);

/**
 * @brief Prints the current state and elements of the ArrayList to stdout.
 * @param list Pointer to the ArrayList.
 */
void print_ArrayList(const ArrayList *list);

#endif // ARRAYLIST_H