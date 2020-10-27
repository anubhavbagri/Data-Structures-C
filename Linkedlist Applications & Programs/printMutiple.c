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
    /* 3. this new node is going to be the last node, so make the next null.*/
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

void print_multiple(node *start, int k)
{
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    int i = 0;
    node *ptr = start;
    while (ptr != NULL)
    {
        if (i % k == 0)
            printf("%d ", ptr->data);
        i++;
        ptr = ptr->next;
    }
}

int main()
{
    node *start = NULL;
    printf("\nPress 1 to insert Node (at the End).");
    printf("\nPress 2 to print all elements at index of multiples of k.");
    printf("\nPress 0 to exit.\n");
    while (1)
    {
        int ch, d, x;
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
            printf("\nEnter the value of k : ");
            scanf("%d", &x);
            printf("\n");
            print_multiple(start, x);
            break;
        default:
            printf("Invalid Choice.");
            return;
        }
    }
}