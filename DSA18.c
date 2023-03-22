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
    q->front = -1;
    q->rear = -1;
}
// int is_full(struct circular_q *q)
// {
//     if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == q->size))
//     {
//         return 1;
//     }
//     return 0;
// }
// int is_empty(struct circular_q *q)
// {
//     if ((q->rear == q->front) || (q->front == 0 && q->rear == 0))
//     {
//         return 1;
//     }
//     return 0;
// }
// void add(struct circular_q *q, int data)
// {
//     if (is_full(q))
//     {
//         printf("Queue overflow\n");
//     }
//     else
//     {
//         q->rear = (q->rear + 1) % q->size;
//         q->arr[q->rear] = data;
//     }
// }
// // int dequeue(struct circular_q *q)
// // {
// //     if (is_empty(q))
// //     {
// //         printf("Queue underflow\n");
// //     }
// //     int data = q->arr[q->front];
// //     q->front = (q->front + 1) % q->size;
// //     return data;
// // }
void display(struct circular_q *q)
{
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
}
// void enqueue(struct circular_q *q, int data)
// {
//     if (is_full(q))
//     {
//         printf("Queue Overflow\n");
//         return;
//     }
//     q->arr[q->rear++] = data;
// }
// int dequeue(struct circular_q *q)
// {
//     if (is_empty(q))
//     {
//         printf("underflow\n");
//         return -1;
//     }
//     else
//     {
//         return q->arr[q->front++];
//     }
// }
void enqueue(struct circular_q *q, int data)
{
    if (q->rear == q->size)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->arr[q->rear++] = data;
    }
    else if (q->front != 0 and q->rear == q->size - 1)
    {
        q->rear = 0;
        q->arr[q->rear++] = data;
    }
    else
    {
        q->arr[q->rear++] = data;
    }
}
int dequeue(struct circular_q *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("underflow");
    }
    int data = q->arr[q->front++];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    if (q->front == q->size - 1)
    {
        q->front = 0;
    }
    return data;
}
int main(int argc, char **argv)
{
    struct circular_q cq;
    init_circular_q(&cq, 5);
    // add(&cq, 100);
    // add(&cq, 200);
    // add(&cq, 300);
    // add(&cq, 400);
    // dequeue(&cq);
    // enqueue(&cq, 100);
    // enqueue(&cq, 200);
    // enqueue(&cq, 300);
    // enqueue(&cq, 400);
    // dequeue(&cq);
    // dequeue(&cq);
    // dequeue(&cq);
    // dequeue(&cq);
    // enqueue(&cq, 1);
    // enqueue(&cq, 2);
    // display(&cq);
    // enqueue(&cq, 1);
    // enqueue(&cq, 2);
    // enqueue(&cq, 3);
    // enqueue(&cq, 4);
    // enqueue(&cq, 5);
    // dequeue(&cq);
    // dequeue(&cq);
    // dequeue(&cq);
    // enqueue(&cq, 100);
    // enqueue(&cq, 200);
    // display(&cq);
    return 0;
}

// circular increment = (i+1)%size