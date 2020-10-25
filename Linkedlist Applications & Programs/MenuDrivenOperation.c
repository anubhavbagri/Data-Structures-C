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

void deleteLast(node **start)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }
    node *ptr = *start;
    if (ptr->next == NULL)
    {
        printf("\nDeleted Value : %d\n", ptr->data);
        ptr = NULL;
        *start = NULL;
        free(ptr);
        return;
    }
    node *last = *start;
    node *second_last;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    printf("\nDeleted Value : %d\n", last->data);
    second_last->next = NULL;
    free(last);
}

void deletePos(node **start, int pos)
{
    if ((*start) == NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *temp = *start;
    if (pos == 1)
    {
        printf("\nNode deleted.");
        *start = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid Position.");
        return;
    }
    node *ptr = temp->next->next;
    free(temp->next);
    temp->next = ptr;
}

int main()
{
    node *start = NULL;
    printf("\nOperations on Singly LinkedList - \n");
    printf("\nPress 1 to insert Node at the beginning.");
    printf("\nPress 2 to insert Node at the End.");
    printf("\nPress 3 to insert Node at inputted position k.");
    printf("\nPress 4 to delete Node from the beginning.");
    printf("\nPress 5 to delete node from the end.");
    printf("\nPress 6 to delete node from the inputted position k.");
