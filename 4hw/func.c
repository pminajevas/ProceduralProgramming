#include "func.h"
#include <stdlib.h>
#include <stdio.h>


/*Function that inserts element before required element*/
void insertBeforeInList(int num, oneWayList **head, int index){
    /* Two possible casses - if new head is needed and inserting before any other element */
    if (index == 1) {
        oneWayList *newNode = NULL;
        newNode = (oneWayList *)malloc(sizeof(oneWayList));
        newNode->data = num;
        newNode->next = (*head);
        (*head) = newNode;

        return;
    }/* Case 1 - new head needed */
    else{
        oneWayList *temp = NULL, *element = *head, *newNode = NULL;
        int i = 0;

        for (i = 0; i < index-1; ++i) {
            temp = element;

            if (element->next == NULL) {
                printf("Element doesn't exist in the list\n");
                return;
            }else{/* If element doesn't exist */
                element = element->next;
            } /* If element exists*/
        }

        newNode = (oneWayList *)malloc(sizeof(oneWayList));
        newNode->data = num;
        newNode->next = temp->next;
        temp->next = newNode;

        return;
    }/* Case 2 - inserting before any other element */
}

/* Function to print the whole list */
void printList(oneWayList *node){

    printf("Here is your list:\n");

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

/* Function to delete one way list */
void deleteList(oneWayList **head)
{
    /* Initialize all values */
    oneWayList *current = *head, *next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    } /* While there are nodes keep on freeing */

    /* Derefference the head */
    *head = NULL;
}
