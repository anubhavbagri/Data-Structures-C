#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;

void insertAtFront(node **start, int d)
{
    node* newNode = (node *)malloc(sizeof(node));
    newNode->data = d;

    newNode->next = (*start);
    newNode->prev = NULL;

    if ((*start) != NULL)
    {
        (*start)->prev = newNode;
    }

    (*start) = newNode;
}

void insertAtEnd(node **start, int d)
{
    node * newNode = (node *) malloc(sizeof(node));
    node* last = *start;

    newNode->data = d;
    newNode->next = NULL;

    if (*start == NULL)
    {
        newNode->prev = NULL;
        *start = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void insertAfterValue(node *start, int searchElement, int d)
{
    if (start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    while(start)
    {
        if(start->data==searchElement)
        {
            node * newNode = (node *) malloc(sizeof(node));
            newNode->data = d;

            newNode->next = start->next;
            start->next = newNode;
            newNode->prev = start;

            if(newNode->next != NULL)
            {
                newNode->next->prev = newNode;
            }
            printf("%d successfully inserted after %d",d,searchElement);
            return;
        }
        start=start->next;
    }
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

    if((*start)->next == NULL) //case of single node.
    {
        *start = NULL;
        free(start);
        return;
    }
    node *temp = *start;

    *start = (*start)->next;
    (*start)->prev = NULL;

    free(temp);
}

void deleteLast(node **start)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }

    if ((*start)->next == NULL) //case of single node.
    {
        printf("Deleted Value : %d",(*start)->data);
        *start = NULL;
        free(start);
        return;
    }

    node *ptr = *start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("Deleted Value : %d",ptr->data);
    ptr->prev->next = NULL;
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
    node *temp;
    while(ptr)
    {
        if(ptr->data == searchElement)
        {
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("\nValue not found. Deletion not possible.\n");
        return;
    }
    if(ptr->next == NULL) //case of single node.
    {
        printf("\nDeletion not possible.");
        return;
    }
    if(ptr->next->next == NULL)
    {
        temp = ptr->next;
        ptr->next = NULL;
        printf("Deleted Value : %d",temp->data);
        free(temp);
        return;
    }
    temp = ptr->next;
    printf("Deleted Value : %d",temp->data);
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
}

void search(node *start, int searchElement)
{
    if (start == NULL)
    {
        printf("\nNo node to perform search.");
        return;
    }
    int c=1;
    while(start)
    {
        if(start->data == searchElement)
        {
            printf("\nValue found at position %d",c);
            return;
        }
        start=start->next;
        c++;
    }
    printf("\nValue not found.");
}

void display(node *start)
{
    if(start==NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *last;
    printf("\nList in forward direction : [");
    while(start)
    {
        printf("%d ", start->data);
        last = start;
        start = start->next;
    }
    printf("]\n");

    /*printf("\nList in backward direction : [");
    while(last)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("]\n");*/
}

int main()
{
    node *start = NULL;
    while(1)
    {
        int ch,d,se;
        printf("\nOperations on Doubly LinkedList - \n");
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
