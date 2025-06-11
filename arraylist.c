#include "arraylist.h" // Include our custom header
#include <string.h>    // Required for memmove
#include <errno.h>     // For errno and perror

// --- Static Helper Function (not exposed in header) ---

/**
 * @brief Resizes the underlying array of the ArrayList.
 * This is an internal helper function.
 * @param list Pointer to the ArrayList.
 * @param new_capacity The new capacity for the array.
 * @return ARRAYLIST_SUCCESS on success, ARRAYLIST_FAILURE on memory reallocation failure.
 */
static int resize_ArrayList(ArrayList *list, int new_capacity) {
    // If new_capacity is smaller, ensure it's not less than current size
    if (new_capacity < list->size && new_capacity > 0) {
        // This case should ideally not happen or handled carefully by caller.
        // For shrinking, new_capacity should be at least list->size.
        // If shrinking, ensure data integrity.
        // For simplicity, let's just make sure new_capacity is positive.
    }
    if (new_capacity <= 0 && list->size > 0) { // Can't shrink to 0 if elements exist
        return ARRAYLIST_FAILURE;
    }

    int *new_data = (int *)realloc(list->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        perror("Memory reallocation failed"); // Use perror for system errors
        return ARRAYLIST_FAILURE;
    }
    list->data = new_data;
    list->capacity = new_capacity;
    return ARRAYLIST_SUCCESS;
}

// --- ArrayList Function Implementations ---

ArrayList create_ArrayList(int initial_capacity) {
    ArrayList list;
    // Ensure a positive initial capacity, default to 4 if non-positive
    if (initial_capacity <= 0) {
        initial_capacity = 4;
    }

    list.data = (int *)malloc(initial_capacity * sizeof(int));
    if (list.data == NULL) {
        perror("Memory allocation failed for ArrayList creation");
        list.size = 0;
        list.capacity = 0;
        return list; // Return a list indicating failure (data is NULL)
    }
    list.size = 0;
    list.capacity = initial_capacity;
    return list;
}

int append_ArrayList(ArrayList *list, int value) {
    // Check if resize is needed before appending
    if (list->size >= list->capacity) {
        // Double the capacity (common strategy for amortized O(1) append)
        if (resize_ArrayList(list, list->capacity * 2) != ARRAYLIST_SUCCESS) {
            return ARRAYLIST_FAILURE; // Failed to resize
        }
    }
    list->data[list->size] = value; // Place value at current end
    list->size++;                    // Increment size
    return ARRAYLIST_SUCCESS;
}

int insert_ArrayList(ArrayList *list, int index, int value) {
    // Validate index: must be within [0, current size]
    // index == list->size is allowed for appending at the end
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Error: Index %d out of bounds for insert (size %d).\n", index, list->size);
        return ARRAYLIST_OUT_OF_BOUNDS;
    }

    // Check if resize is needed before inserting
    if (list->size >= list->capacity) {
        if (resize_ArrayList(list, list->capacity * 2) != ARRAYLIST_SUCCESS) {
            return ARRAYLIST_FAILURE; // Failed to resize
        }
    }

    // Shift elements to the right to make space for the new value
    // memmove is safe for overlapping memory regions (like this shift)
    // Copies (list->size - index) elements starting from list->data[index]
    // to list->data[index + 1]
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(int));
    
    list->data[index] = value; // Insert the new value at the desired index
    list->size++;                // Increment size
    return ARRAYLIST_SUCCESS;
}

int indexOf_ArrayList(const ArrayList *list, int value) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == value) {
            return i; // Return the index if value is found
        }
    }
    return -1; // Return -1 if value is not found
}

int deleteAt_ArrayList(ArrayList *list, int index) {
    // Validate index: must be within [0, size - 1]
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Error: Index %d out of bounds for deletion (size %d).\n", index, list->size);
        return ARRAYLIST_OUT_OF_BOUNDS;
    }

    // Shift elements to the left to fill the gap
    // memmove is safe for overlapping memory regions (like this shift)
    // Copies (list->size - index - 1) elements starting from list->data[index + 1]
    // to list->data[index]
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(int));
    
    list->size--; // Decrement size

    // Optional: Shrink capacity if current size is significantly smaller than capacity
    // This helps reclaim unused memory, preventing excessive memory consumption.
    // Example: Shrink if size is less than 1/4 of capacity, but don't shrink too small (min capacity 4)
    if (list->capacity > 4 && list->size < list->capacity / 4) {
        // Attempt to halve the capacity
        resize_ArrayList(list, list->capacity / 2);
        // Note: We ignore return status here because shrinking is an optimization,
        // and failure means we just keep the larger capacity, which is acceptable.
    }

    return ARRAYLIST_SUCCESS;
}

int removeLast_ArrayList(ArrayList *list) {
    if (list->size == 0) {
        fprintf(stderr, "Error: ArrayList is empty, nothing to remove from last.\n");
        return ARRAYLIST_EMPTY_ERROR;
    }
    list->size--; // Simply decrement size to logically remove the last element

    // Optional: Shrink capacity (same logic as deleteAt_ArrayList)
    if (list->capacity > 4 && list->size < list->capacity / 4) {
        resize_ArrayList(list, list->capacity / 2);
    }
    return ARRAYLIST_SUCCESS;
}

void clear_ArrayList(ArrayList *list) {
    list->size = 0; // Reset size to 0; elements are logically removed, memory is retained for reuse
    // To also free the memory aggressively upon clear, you could call:
    // resize_ArrayList(list, initial_capacity_for_clear); // Or a fixed small capacity
}

void destroy_ArrayList(ArrayList *list) {
    if (list != NULL && list->data != NULL) {
        free(list->data);    // Free the dynamically allocated array
        list->data = NULL;   // Set pointer to NULL to prevent dangling pointers/double free
        list->size = 0;      // Reset size
        list->capacity = 0;  // Reset capacity
    }
}

void print_ArrayList(const ArrayList *list) {
    printf("ArrayList (size: %d, capacity: %d): [", list->size, list->capacity);
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}