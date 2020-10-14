#include <stdio.h>
#include<stdlib.h>

int stack[100],choice,n,top,x,i;

void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK overflow");

    }
    else
    {
        printf("\n\tEnter a value to be pushed : ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\tStack underflow");
    }
    else
    {
        printf("\n\tThe popped element is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

int main()
{
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    while(1)
    {
        printf("\n Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("\n\t Invalid choice.");
        }
    }
}
