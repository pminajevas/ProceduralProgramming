#ifndef MyLibH
#define MyLibH

/* Creating structure */
struct oneWayList{
    int data;
    struct oneWayList *next;
};

typedef struct oneWayList oneWayList;

extern void insertBeforeInList(int num, oneWayList **head, int index);
extern void printList(oneWayList *node);
extern void deleteList(oneWayList **head);

#endif
