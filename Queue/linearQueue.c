#include <stdio.h>

struct Queue
{
    int *buffer;
    int front, rear, size;
};
typedef struct Queue Q;
Q createQ(int size)
{
    Q queue;
    queue.buffer = (int *)malloc(sizeof(int) * size);
    queue.front = -1;
    queue.rear = -1;
    queue.size = size;
    return queue;
}
int isEmpty(Q *queue)
{
    return queue->front == -1;
}
int isFull(Q *queue)
{
    return queue->rear == queue->size - 1;
}
void enqueue(Q *queue, int data)
{
    if (isFull(queue))
    {
        printf("\nQueue is full, insert operation is not possible.");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
        queue->buffer[queue->front] = data;
        return;
    }
    queue->buffer[++(queue->rear)] = data;
}
void dequeue(Q *queue)
{
    if (isEmpty(queue))
    {
        printf("\nEmpty Queue! Process not possible.\n");
        return;
    }
    int value = queue->buffer[queue->front];
    printf("\nProcessed data : %d", value);
    (queue->front)++;

    if (queue->front > queue->rear)
    { //buffer recycling condition.
        queue->front = queue->rear = -1;
    }
}
void displayQueue(Q *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is empty!");
        return;
    }
    int i;
    printf("\nQueue : ");
    for (i = queue->front; i <= queue->rear; i++)
    {
        printf("--->%d", queue->buffer[i]);
    }
    printf("\n");
}
int main()
{
    int size, ch, data;
    Q q;
    printf("\nEnter the size of queue : ");
    scanf("%d", &size);
    q = createQ(size);
    while (1)
    {
        printf("\n1. Enqueue.");
        printf("\n2. Dequeue.");
        printf("\n3. Display Queue.");
        printf("\n0. Exit.");
        printf("\nEnter your choice (0-3) : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\nEnter data to insert into queue : ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        }
        case 2:
        {
            dequeue(&q);
            break;
        }
        case 3:
        {
            displayQueue(&q);
            break;
        }
        case 0:
        {
            exit(ch);
        }
        default:
            printf("\nWrong option selected.");
        }
    }
    return 0;
}