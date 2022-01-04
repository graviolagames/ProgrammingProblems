
#include "lList.h"
#include <stdio.h>
#include <stdlib.h>

lList * sumTwoNumbers(lList *A,lList *B);
int main()
{
    //Populate two numbers on linked lists
    int A[] = {2,4,3};
    int B[] = {5,6,4,2};
    lList *listA = createList(A,3);
    printf("A = "); printList(listA);
    lList *listB = createList(B,4);
    printf("B = ");printList(listB);
    lList *sumList = sumTwoNumbers(listA,listB);
    printf("Sum = ");printList(sumList);
    destroyList(listA);
    destroyList(listB);
    destroyList(sumList);
    return 0;
}

lList * sumTwoNumbers(lList *A,lList *B)
{
    if(A==NULL||B==NULL)
        return NULL;
    lList *ret = NULL;
    lList *retEnd = NULL;
    lList *nodeA = A;
    lList *nodeB = B;
    int borrow = 0;
    while(1)
    {
        int digitA = 0;
        int digitB = 0;
        int sumDigit = 0;
        if(nodeA != NULL)
            {
                digitA = nodeA->value; 
                nodeA = nodeA->next;
            }
        if(nodeB != NULL)
            {
                digitB = nodeB->value;
                nodeB = nodeB->next;
            }
        printf("%d ",borrow);
        sumDigit = digitA+digitB+borrow;
        borrow = sumDigit/10;
        sumDigit = sumDigit%10;
        printf("+%d , +%d, =%d, borrow=%d \n",digitA,digitB,sumDigit,borrow);
        lList *newRetDigit = malloc(sizeof(lList));
        newRetDigit->value = sumDigit;
        newRetDigit->next = NULL;
        if(ret == NULL)
            {
                ret = newRetDigit;
                retEnd = ret;
            }
        else
            {
                retEnd->next = newRetDigit;
                retEnd = newRetDigit;
            } 

        if(nodeA == NULL && nodeB == NULL)
            break;
        
    }
    
    return ret;
}
