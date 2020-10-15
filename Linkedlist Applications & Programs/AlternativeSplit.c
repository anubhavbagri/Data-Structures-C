#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void MoveNode(node **endRef, node **startRef)
{
    node *newNode = *startRef;
    if(newNode == NULL)
        return;
    *startRef = newNode->next;
    newNode->next = *endRef;
    *endRef = newNode;
}

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

int main()
{
    node *start = NULL, *a = NULL, *b = NULL;
    printf("\nPress 1 to insert Node (at the End).");
    printf("\nPress 2 to divide list into alternate elements and display.");
    printf("\nPress 0 to exit.\n");
    while (1)
    {
        int ch, d, pos, x;
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(ch); //return
        case 1:
            printf("\nEnter data to be inserted : ");
            scanf("%d", &d);
            insertAtEnd(&start, d);
            break;
        case 2:
            alternateSplit(start,&a,&b);
            printf("\nFirst List - \n");
            display(a);
            printf("\nSecond List - \n");
            display(b);
            break;
        default:
            printf("Invalid Choice.");
        }
    }
}