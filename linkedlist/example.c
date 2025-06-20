#include "singly_linkedlist.h"

int main(){
    SinglyLinkedList* list = Singly_LinkedList();
    
    push_head_LinkedList(list,6);
    push_head_LinkedList(list,7);
    push_head_LinkedList(list,13);
    push_head_LinkedList(list,45);
    push_head_LinkedList(list,43356);
    push_head_LinkedList(list,465);
    push_head_LinkedList(list,5);
    push_head_LinkedList(list,3);
    push_tail_LinkedList(list, 100);
    
    print_LinkedList(list);

    pop_LinkedList(list);
    print_LinkedList(list);

    DATATYPE to_search = 4;
    printf(search_LinkedList(list,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    to_search = 43356;
    printf(search_LinkedList(list,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    modify_LinkedList(list, 43356, 4);
    print_LinkedList(list);

    to_search = 4;
    printf(search_LinkedList(list,to_search)? "'%d' Found\n" : "'%d' Not Found\n", to_search);

    printf("Head element: %d\n", peek_head_LinkedList(list));
    printf("Tail element: %d\n", peek_tail_LinkedList(list));

    printf(isEmpty_LinkedList(list) ? "Empty\n" : "Not Empty\n");
    clear_LinkedList(list);
    pop_LinkedList(list); // This should trigger underflow
    printf(isEmpty_LinkedList(list) ? "Empty\n" : "Not Empty\n");

    free(list); // Free the linked list structure

    return 0;
}


// run this code with the following command:
// gcc singly_linkedlist.c example.c -o singly_linkedlist_test