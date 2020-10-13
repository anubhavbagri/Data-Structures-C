#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtFront(node **start, int data)
{
    /* 1. allocate node */
    node * newNode = (node *) malloc(sizeof(node));
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
    node * newNode = (node *) malloc(sizeof(node));
    /* 2. put the data into newNode. */
    newNode->data = d;
    /* 3. this new node is going to be the last node, so make the next null. */
    newNode->next = NULL;

    /* 4. if the linked list is empty, then make the newNode as start. */
    if(*start == NULL)
    {
        *start = newNode;
        return;
    }
    /*5. Else traverse till the last node */
    node *last = *start;
    while(last->next != NULL)
    {
        last = last->next;
    }
    /*6. change the next of the last node */
    last->next = newNode;
}

void insertAfterNode(node *prevNode, int d)
{
    /*1. check if the given prevNode is NULL.*/
    if(prevNode == NULL)
    {
        printf("\nThe given prevNode cannot be NULL.");
        return;
    }
    /*2. allocate new node */
    node * newNode = (node *) malloc(sizeof(node));

    /* 3. put the data into the new node */
    newNode->data = d;

    /* 4. Make next of newNode as next of prevNode */
    newNode->next = prevNode->next;

    /* 5. Move the next of prevNode as newNode */
    prevNode->next = newNode;
}

void deleteFirst(node **start)
{
    if (*start == NULL)
    {
        printf("\nNo node to delete.");
        return;
    }
    printf("Deleted Value : %d",(*start)->data);

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
        printf("Deleted Value : %d",ptr->data);
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
    printf("Deleted Value : %d",last->data);
    second_last->next = NULL;
    free(last);
}

void searchAndInsertAfter(node *start, int searchElement, int d)
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
            insertAfterNode(start,d);
            printf("%d successfully inserted after %d",d,searchElement);
            return;
        }
        start=start->next;
    }

    printf("\n%d is not found.",searchElement);
}

void deleteAfter(node **start, int searchElement)
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
    }while(ptr && preptr->data != searchElement);

    if(ptr == NULL)
    {
        printf("\nCannot perform deletion.\n");
        return;
    }

    printf("\n%d deleted Successfully.\n",ptr->data);
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
    while(start)
    {
        if(start->data==searchElement)
        {
            printf("\nValue found at position %d\n",c);
            return;
        }
        start=start->next;
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
    node *start = NULL;
    while(1)
    {
        int ch,d,se;
        printf("\nOperations on Singly LinkedList - \n");
        printf("\nPress 1 to insert Node at the beginning.");
        printf("\nPress 2 to insert Node at the End.");
        printf("\nPress 3 to delete Node from the beginning.");
        printf("\nPress 4 to delete Node from the end.");
        printf("\nPress 5 to insert node after your given value.");
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
            deleteFirst(&start);
            break;
        case 4:
            deleteLast(&start);
            break;
        case 5:
            printf("\nEnter value after which node will be inserted: ");
            scanf("%d",&se);
            printf("\nEnter data to be inserted after searched value: ");
            scanf("%d",&d);
            searchAndInsertAfter(start,se,d);
            break;
        case 6:
            printf("\nEnter the value after which node has to be deleted: ");
            scanf("%d",&se);
            deleteAfter(&start,se);
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
