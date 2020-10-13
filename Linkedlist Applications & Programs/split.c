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

void split(node **start, node **frontRef, node **backRef)
{
    if ((*start) == NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *temp = (*start);
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (c < 2)
    {
        *frontRef = (*start);
        *backRef = NULL;
        return;
    }
    node *current = (*start);
    int count = (c - 1) / 2;
    for (int i = 0; i < count; i++)
    {
        current = current->next;
    }
    *frontRef = (*start);
    *backRef = current->next;
    current->next = NULL;
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

int main()
{
    node *start = NULL, *a = NULL, *b = NULL;
    printf("\nPress 1 to insert Node (at the End).");
    printf("\nPress 2 to split list and display.");
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
            split(&start, &a, &b);
            printf("\nFront Half - \n");
            display(a);
            printf("\nBack Half - \n");
            display(b);
            break;
        default:
            printf("Invalid Choice.");
        }
    }
}