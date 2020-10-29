#include<stdio.h>
#include<stdlib.h>

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

void remove_greater(node **start)
{
    node *ptr = *start, *preptr, *ptrnext = ptr->next, *temp;
    if(ptr == NULL || ptrnext == NULL)
    {
        return;
    }
    preptr = *start;
    while (ptr->next != NULL)
    {
        if (ptr->data < ptrnext->data)
        {
            if (ptr == *start)
            {
                temp = ptr;
                *start = ptr->next;
                ptr = *start;
                ptrnext = ptrnext->next;
                free(temp);
            }
            else
            {
                temp = ptr;
                preptr->next = ptrnext;
                temp->next = NULL;
                free(temp);
                ptr = preptr->next;
                ptrnext = ptrnext->next;
            }
        }
        else
        {
            preptr = ptr;
            ptr = ptrnext;
            ptrnext = ptrnext->next;
        }
    }
}

void pairWiseSwap(node **start)
{
    if (*start == NULL || (*start)->next == NULL)
    {
        printf("Pairwise Swapping not possible.");
        return;
    }
    node *prev = *start;
    node *curr = (*start)->next;
    *start = curr;
    while (1)
    {
        node *next = curr->next;
        curr->next = prev;
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    printf("\nPairwise Swapping done successfully.\n");
}

void display(node *start)
{
    if(start==NULL)
    {
        printf("List is Empty.");
        return;
    }
    printf("\nList : [");
    while(start)
    {
        printf("%d ", start->data);
        start=start->next;
    }
    printf("]\n");
}