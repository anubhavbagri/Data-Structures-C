#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtFront(node **start, int d)
{
    node * newNode = (node *) malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;
    node *ptr = *start;
    if(ptr == NULL) //1st node insertion
    {
        *start = newNode;
        newNode->next = *start;
        return;
    }
    while(ptr->next != (*start))
    {
        ptr = ptr->next;
    }
    newNode->next = *start;
    ptr->next = newNode;
    *start = newNode;
    printf("\nInserted Successfully.\n");
}

void insertAtEnd(node **start, int d)
{
    node * newNode = (node *) malloc(sizeof(node));
    newNode->data = d;
    newNode->next = *start;
    node *ptr = *start;
    while(ptr->next != (*start))
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    printf("\nInserted Successfully.\n");
}

void insertAfterValue(node *start, int searchElement, int d)
{
    if (start == NULL)
    {
        printf("\nList is empty.");
        return;
    }
    node *ptr = start;
    do
    {
        if(ptr->data==searchElement)
        {
            node * newNode = (node *) malloc(sizeof(node));
            newNode->data = d;
            newNode->next = ptr->next;
            ptr->next = newNode;
            printf("%d successfully inserted after %d",d,searchElement);
            return;
        }
        ptr=ptr->next;
    }
    while(ptr != start);
    printf("\n%d is not found.",searchElement);
}

void deleteFirst(node **start)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }
    printf("Deleted Value : %d",(*start)->data);

    node *ptr = *start;
    if(ptr->next == (*start)) //case of single node.
    {
        *start = NULL;
        free(ptr);
        return;
    }
    node *first = *start;
    while(ptr->next != (*start))
    {
        ptr = ptr->next;
    }
    ptr->next = (*start)->next;
    *start = (*start)->next;
    first->next = NULL;
    free(first);
}

void deleteLast(node **start)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }
    node *ptr = *start;
    if ((*start)->next == (*start))
    {
        printf("Deleted Value : %d",(*start)->data);
        *start = NULL;
        free(ptr);
        return;
    }
    node *preptr = ptr;
    while (ptr->next != (*start))
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    printf("Deleted Value : %d",ptr->data);
    ptr = NULL;
    preptr->next=(*start);
    free(ptr);
}

void deleteAfterValue(node **start, int searchElement)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }
    node *ptr = *start;
    node *preptr;

    do
    {
        preptr = ptr;
        ptr = ptr->next;
    }while(ptr != (*start) && preptr->data != searchElement);

    if(ptr == (*start) && ptr == preptr->next)
    {
        printf("\nDeletion not possible.\n");
        return;
    }

    printf("\n%d deleted successfully.",ptr->data);
    preptr->next = ptr->next;
    ptr->next = NULL;
    free(ptr);
}

void search(node *start, int searchElement)
{
    if (start == NULL)
    {
        printf("\nList is empty.");
        return;
    }
    int c=1;
    node *ptr = start;
    while(ptr)
    {
        if(ptr->data==searchElement)
        {
            printf("\nValue found at position %d\n",c);
            return;
        }
        if(ptr->next == start)
        {
            break;
        }
        ptr=ptr->next;
        c++;
    }
    printf("\n%d is not found.",searchElement);
}

void display(node *start)
{
    if(start==NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *ptr = start;
    printf("\nList : [");
    do
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    while(ptr != start);
    printf("]\n");
}

int main()
{
    node *start = NULL;
    while(1)
    {
        int ch,d,se;
        printf("\nOperations on Circular LinkedList - \n");
        printf("\nPress 1 to insert Node at the beginning.");
        printf("\nPress 2 to insert Node at the End.");
        printf("\nPress 3 to insert node after your given value.");
        printf("\nPress 4 to delete Node from the beginning.");
        printf("\nPress 5 to delete Node from the end.");
        printf("\nPress 6 to delete node after your given value.");
        printf("\nPress 7 to search a value in the list.");
        printf("\nPress 8 to display the list.");
        printf("\nPress 0 to exit.\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            exit(ch); //return
        case 1:
            printf("\nEnter data to be inserted at the beginning: ");
            scanf("%d",&d);
            insertAtFront(&start,d);
            break;
        case 2:
            printf("\nEnter data to be inserted at the end: ");
            scanf("%d",&d);
            insertAtEnd(&start,d);
            break;
        case 3:
            printf("\nEnter value after which node will be inserted: ");
            scanf("%d",&se);
            printf("\nEnter data to be inserted after searched value: ");
            scanf("%d",&d);
            insertAfterValue(start,se,d);
            break;
        case 4:
            deleteFirst(&start);
            break;
        case 5:
            deleteLast(&start);
            break;
        case 6:
            printf("\nEnter the value after which node has to be deleted: ");
            scanf("%d",&se);
            deleteAfterValue(&start,se);
            break;
        case 7:
            printf("\nEnter value to be searched: ");
            scanf("%d",&se);
            search(start,se);
            break;
        case 8:
            display(start);
            break;
        default:
            printf("Invalid Choice.");
        }
    }
}

