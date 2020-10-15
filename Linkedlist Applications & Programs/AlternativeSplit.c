#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtEnd(node **start, int d)
{
    /* 1. allocate new node. */
    node *newNode = (node *)malloc(sizeof(node));
    /* 2. put the data into newNode. */
    newNode->data = d;
    /* 3. this new node is going to be the last node, so make the next null. */
    newNode->next = NULL;
    /* 4. if the linked list is empty, then make the newNode as start. */
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    /*5. Else traverse till the last node */
    node *last = *start;
    while (last->next != NULL)
    {
        last = last->next;
    }
    /*6. change the next of the last node */
    last->next = newNode;
}

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