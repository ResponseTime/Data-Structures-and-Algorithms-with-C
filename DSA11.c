#include <stdio.h>
#include <stdlib.h>
struct circle
{
    int data;
    struct circle *next;
};
struct circle *head;
void add(int data)
{
    struct circle *temp = (struct circle *)malloc(sizeof(struct circle));
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        struct circle *new = head;
        while (new->next != head)
        {
            new = new->next;
        }
        temp->next = head;
        new->next = temp;
        head = temp;
    }
}
void display()
{
    struct circle *temp = head;
    while (temp->next != head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
void insert_first(int data)
{
    struct circle *temp = (struct circle *)malloc(sizeof(struct circle));
    temp->data = data;
    struct circle *n = head;
    while (n->next != head)
    {
        n = n->next;
    }
    n->next = temp;
    temp->next = head;
    head = temp;
}
int main(int argc, char **argv)
{

    add(1);
    add(2);
    add(3);
    insert_first(666);
    display();
    return 0;
}