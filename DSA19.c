#include <stdio.h>
#include <stdlib.h>

struct linkedQ
{
    int data;
    struct linkedQ *next;
};

struct linkedQ *front;
struct linkedQ *rear;

void enqueue(int data)
{
    struct linkedQ *temp = (struct linkedQ *)malloc(sizeof(struct linkedQ));
    temp->data = data;
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
int dequeue()
{
    if (front == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {

        int data = front->data;
        struct linkedQ *temp = front;
        front = front->next;
        free(temp);
        return data;
    }
}

void is_empty()
{
    if (front == NULL)
    {
        printf("Queue empty");
    }
    else
    {
        printf("Queue not empty");
    }
}

void display()
{
    struct linkedQ *t = front;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}
int main(int argc, char **argv)
{
    // is_empty();
    enqueue(423);
    enqueue(43);
    enqueue(3);
    enqueue(3);
    dequeue();
    display();
    is_empty();
    return 0;
}