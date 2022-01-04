#include "lList.h"
#include <stdio.h>
#include <stdlib.h>

void printList(lList *list)
{
    if(list == NULL)
        {
            printf("list = NULL \n");
            return;
        }
    lList *node = list;
    printf("{");
    while(1)
    {
        printf("%d",node->value);
        node = node->next;
        if(node == NULL)
            break;
        printf("->");
    }
    printf("}\n");
}

lList * createList(int *digitArray,int len)
{
    
    lList *ret = NULL;
    lList *end = NULL;
    for(int i = 0; i < len; i++)
    {
        lList *node = malloc(sizeof(lList)); 
        node->value = digitArray[i];
        node->next = NULL;
        if(ret==NULL)
            {
                ret = node;
                end = ret;
            }
        else
            {
               end->next = node;
               end = node;
            }

    }
    return ret;
}

void destroyList(lList *list)
{
    if(list == NULL)
        return;
    lList *node = list;
    lList *nextNode = list->next;
    free(node);
    while(nextNode!=NULL)
    {
        node = nextNode;
        nextNode = node->next;
        free(node);
    }
}