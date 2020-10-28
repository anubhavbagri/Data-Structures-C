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
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = *start;
    if (*start == NULL)
    {
        *start = newNode;
        newNode->next = *start;
        return;
    }
    node *ptr = *start;
    while (ptr->next != (*start))
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    // printf("\nInserted Successfully.\n");
}

void circular_multiple(node *start, int k)
{
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    int count = 0;
    node *ptr = start;
    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != start);
    int num = 0;
    while (count != 0)
    {
        if (num % k == 0 && ptr->data != -1)
        {
            printf("%d ", ptr->data);
            ptr->data = -1;
            count--;
        }
        num++;
        ptr = ptr->next;
    }
}

int main()
{
    node *start = NULL;
    printf("\nPress 1 to insert Node (at the End).");
    printf("\nPress 2 to print all elements at index of multiples of k in circular list.");
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
            circular_multiple(start, x);
            break;
        default:
            printf("Invalid Choice.");
            return;
        }
    }
}