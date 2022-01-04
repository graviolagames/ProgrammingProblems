#ifndef lList_h
#define lList_h

//Linked list structure
#define lList struct linkedList
lList
{
    int value;
    lList* next;
};

lList * createList(int *digitArray,int len);
void destroyList(lList *list);
void printList(lList *list);

#endif
