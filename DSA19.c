#include <stdio.h>
#include <stdlib.h>

struct circular_q
{
    int size;
    int *arr;
    int rear;
    int front;
};

void init_circular_q(struct circular_q *q, int size)
{
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = 0;
}
int is_full(struct circular_q *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    return 0;
}
int is_empty(struct circular_q *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}
void add(struct circular_q *q, int data)
{
    if (is_full(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
    }
}
int dequeue(struct circular_q *q)
{
    if (is_empty(q))
    {
        printf("Queue underflow\n");
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    return data;
}
void display(struct circular_q *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
}
int main(int argc, char **argv)
{
    struct circular_q cq;
    init_circular_q(&cq, 5);
    add(&cq, 100);
    add(&cq, 200);
    add(&cq, 300);
    add(&cq, 400);
    dequeue(&cq);
    display(&cq);
    return 0;
}

// circular increment = (i+1)%size