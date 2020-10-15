#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void alternateSplit(node *start, node **aRef, node **bRef)
{
    node a;
    node *aEnd = &a;
    node b;
    node *bEnd = &b;
    node *current = start;
    a.next = NULL;
    b.next = NULL;
    while(current != NULL)
    {
        MoveNode(&(aEnd->next), &current);
        aEnd = aEnd->next;
        if (current != NULL)
        {
            MoveNode(&(bEnd->next), &current);
            bEnd = bEnd->next;
        }
    }
    *aRef = a.next;
    *bRef = b.next;
}