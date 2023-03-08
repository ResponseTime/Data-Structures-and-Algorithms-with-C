#include <stdio.h>
#include <stdlib.h>

struct doublee
{
    struct doublee *prev;
    int data;
    struct doublee *next;
};

struct doublee *head;

void add(int data)
{
    struct doublee *temp = (struct doublee *)malloc(sizeof(struct doublee));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct doublee *n = head;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = temp;
        temp->prev = n;
    }
}

void display()
{
    struct doublee *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void insert_first(int data)
{
    struct doublee *temp = (struct doublee *)malloc(sizeof(struct doublee));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;
}
void reverse1()
{
    struct doublee *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
void reverse2()
{
    struct doublee *temp = NULL;
    struct doublee *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
}
void insert_last(int data)
{
    struct doublee *temp = head;
    struct doublee *new = (struct doublee *)malloc(sizeof(struct doublee));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    new->prev = temp;
    temp->next = new;
}
int main(int argc, char **argv)
{
    add(1);
    add(2);
    insert_last(999);
    add(3);
    insert_first(666);
    // reverse2();
    display();
    return 0;
}