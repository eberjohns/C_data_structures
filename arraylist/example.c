#include "arraylist.h" // Include our custom ArrayList header
#include <stdio.h>     // For printf

int main() {
    printf("--- Initializing ArrayList ---\n");
    ArrayList my_list = create_ArrayList(2); // Start with initial capacity of 2

    if (my_list.data == NULL) {
        printf("Failed to create ArrayList. Exiting.\n");
        return 1;
    }
    print_ArrayList(&my_list);

    printf("\n--- Appending elements ---\n");
    append_ArrayList(&my_list, 10);
    append_ArrayList(&my_list, 20);
    print_ArrayList(&my_list); // Should be [10, 20], size 2, capacity 2

    printf("\n--- Appending beyond capacity (triggers resize) ---\n");
    if (append_ArrayList(&my_list, 30) == ARRAYLIST_SUCCESS) { // This should trigger a resize to 4
        print_ArrayList(&my_list); // Should be [10, 20, 30], size 3, capacity 4
    } else {
        printf("Failed to append 30.\n");
    }
    
    if (append_ArrayList(&my_list, 40) == ARRAYLIST_SUCCESS) {
        print_ArrayList(&my_list); // Should be [10, 20, 30, 40], size 4, capacity 4
    } else {
        printf("Failed to append 40.\n");
    }

    printf("\n--- Inserting elements ---\n");
    if (insert_ArrayList(&my_list, 0, 5) == ARRAYLIST_SUCCESS) { // Insert at beginning
        print_ArrayList(&my_list); // Should be [5, 10, 20, 30, 40], size 5, capacity 8 (another resize)
    } else {
        printf("Failed to insert 5 at index 0.\n");
    }

    if (insert_ArrayList(&my_list, 3, 25) == ARRAYLIST_SUCCESS) { // Insert in middle
        print_ArrayList(&my_list); // Should be [5, 10, 20, 25, 30, 40]
    } else {
        printf("Failed to insert 25 at index 3.\n");
    }

    printf("\n--- Searching for elements ---\n");
    printf("Index of 30: %d\n", indexOf_ArrayList(&my_list, 30));    // Expected: 4
    printf("Index of 5: %d\n", indexOf_ArrayList(&my_list, 5));      // Expected: 0
    printf("Index of 25: %d\n", indexOf_ArrayList(&my_list, 25));    // Expected: 3
    printf("Index of 99 (not found): %d\n", indexOf_ArrayList(&my_list, 99)); // Expected: -1

    printf("\n--- Deleting elements ---\n");
    if (deleteAt_ArrayList(&my_list, 3) == ARRAYLIST_SUCCESS) { // Delete 25
        print_ArrayList(&my_list); // Should be [5, 10, 20, 30, 40]
    } else {
        printf("Failed to delete at index 3.\n");
    }

    if (removeLast_ArrayList(&my_list) == ARRAYLIST_SUCCESS) { // Remove 40
        print_ArrayList(&my_list); // Should be [5, 10, 20, 30]
    } else {
        printf("Failed to remove last element.\n");
    }

    printf("\n--- Clearing ArrayList ---\n");
    clear_ArrayList(&my_list);
    print_ArrayList(&my_list); // Should be [], size 0, capacity still 8
    
    printf("\n--- Attempting to remove from empty list ---\n");
    if (removeLast_ArrayList(&my_list) != ARRAYLIST_SUCCESS) { // Should print error from function
        printf("Correctly handled removal from empty list.\n");
    }

    printf("\n--- Re-appending after clear ---\n");
    if (append_ArrayList(&my_list, 100) == ARRAYLIST_SUCCESS) {
        print_ArrayList(&my_list); // Should be [100], size 1, capacity 8
    } else {
        printf("Failed to append 100 after clear.\n");
    }

    printf("\n--- Destroying ArrayList ---\n");
    destroy_ArrayList(&my_list); // Free all allocated memory
    print_ArrayList(&my_list); // Should show size 0, capacity 0, data NULL (safely)

    return 0;
}


// run this code with the following command:
// gcc arraylist.c example.c -o arraylist_test