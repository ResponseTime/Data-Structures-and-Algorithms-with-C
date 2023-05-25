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
    return q->arr[q->front++];
}
void display(struct queue *q)
{
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
}
int is_empty(struct queue *q)
{
    if (q->rear == 0 && q->front == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char **argv)
{
    struct queue q;
    queue_init(&q, 400);
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!is_empty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}