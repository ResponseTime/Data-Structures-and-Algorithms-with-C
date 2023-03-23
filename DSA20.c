#include <stdio.h>
#include <stdlib.h>
struct q
{
    int size;
    int *arr;
    int front, rear;
};

void init(struct q *q, int size)
{
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = q->rear = -1;
}
void front_enqueue(struct q *q, int data)
{
    if (q->front == q->rear + 1)
    {
        printf("queue overflow\n");
    }
    else if (q->front != 0)
    {
        q->arr[--q->front] = data;
    }
    else if (q->front == -1)
    {
        q->arr[++q->front] = data;
        q->rear = q->front;
    }
    else
    {
        printf("no space in front to enqueue\n");
    }
}
void back_enqueue(struct q *q, int data)
{
    if (q->front == q->rear + 1)
    {
        printf("queue overflow\n");
    }
    else
    {
        q->arr[q->rear++] = data;
    }
}

int front_dequeue(struct q *q)
{
    if (q->front == -1)
    {
        printf("queue underflow\n");
    }
    else
    {
        return q->arr[q->front++];
    }
}

int back_dequeue(struct q *q)
{
    if (q->front == -1)
    {
        printf("queue underflow\n");
    }
    else
    {
        return q->arr[q->rear--];
    }
}
void display_queue(struct q *q)
{
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
}
int main(int argc, char **argv)
{
    struct q q;
    init(&q, 5);
    front_enqueue(&q, 100);
    front_enqueue(&q, 200);
    back_enqueue(&q, 300);
    front_dequeue(&q);
    back_dequeue(&q);
    display_queue(&q);
    return 0;
}

// two types of DEqueue
// Restricted input DEqueue - insertion from front not allowed
// Restricted output DEqueue - deletion from rear not allowed