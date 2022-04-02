#include <stdlib.h>
#include <stdio.h>
/* Including header file with functions */
#include "func.h"

int main(){
    /* Initializing head structure */
    oneWayList *head = NULL;
    
    /* Printing info message */
    printf("This program can insert an element before provided element in an one way list.\n");

    /* Working with structures */
    /* insertBefore(value, list's head address, index) inserts new element into list before an element */
    /* printList(list's head) prints the whole list) */
    insertBeforeInList(4, &head, 1);
    insertBeforeInList(10, &head, 1);
    insertBeforeInList(7, &head, 2);
    printList(head);
    deleteList(&head);
    printList(head);

    return 0;
}
