#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtFront(node **start, int data)
{
    /* 1. allocate node */
    node *newNode = (node *)malloc(sizeof(node));
    /* 2. put the data into the new node */
    newNode->data = data;
    /* 3. make the next of new node as start*/
    newNode->next = *start;
    /* 4. move the start to point to the new node */
    *start = newNode;
}

void insertAtEnd(node **start, int d)
{
    /* 1. allocate new node. */
    node *newNode = (node *)malloc(sizeof(node));
    /* 2. put the data into newNode. */
    newNode->data = d;
    /* 3. this new node is going to be the last node, so make the next null.
*/
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

void insertPos(node **start, int d, int pos)
{
    if ((*start) == NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *ptr = (*start);
    int size = 0;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    if (pos < 1 || pos > size + 1)
    {
        printf("\nInvalid position.");
        return;
    }
    while (pos--)
    {
        if (pos == 0)
        {
            node *newNode = (node *)malloc(sizeof(node));
            newNode->data = d;
            newNode->next = NULL;
            node *temp = newNode;
            temp->next = *start;
            *start = temp;
        }
        else
            start = &(*start)->next;
    }
    size++;
}

void deleteFirst(node **start)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }
    printf("\nDeleted Value : %d\n", (*start)->data);
    node *temp = *start;
    *start = (*start)->next;
    free(temp);
}