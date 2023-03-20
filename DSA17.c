#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int *arr;
    int rear;
    int front;
};

void queue_init(struct queue *q, int size)
{
    q->size = size;
    q->arr = (int *)calloc(size, sizeof(int));
    q->rear = 0;
    q->front = 0;
}
void enqueue(struct queue *q, int data)
{
    q->arr[q->rear++] = data;
}
int dequeue(struct queue *q)
{
    // int data = q->arr[0];
    // for (int i = 0; i <= q->rear - 1; i++)
    // {
    //     q->arr[i] = q->arr[i + 1];
    // }
    // q->rear--;
    // return data;
    return q->arr[q->front++];
}
void display(struct queue *q)
{
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
}
void is_empty(struct queue *q)
{
    if (q->rear == 0)
    {
        printf("Queue Empty");
    }
    else
    {
        printf("Queue Not Empty");
    }
}
void is_full(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue full");
    }
    else
    {
        printf("Queue Not full");
    }
}
int main(int argc, char **argv)
{
    struct queue q;
    queue_init(&q, 10);
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    enqueue(&q, 400);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}