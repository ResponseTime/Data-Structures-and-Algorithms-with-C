#include <stdio.h>
#include <stdlib.h>
// push --
// pop --
// peek --
// is_empty --
struct list
{
    int data;
    struct list *next;
};
struct list *top;

void push(int data)
{
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    temp->data = data;
    temp->next = NULL;
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void is_empty()
{
    if (top == NULL)
    {
        printf("The stack is empty");
    }
}
int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow");
    }
    struct list *temp = top;
    int data = top->data;
    top = top->next;
    free(temp);
    return data;
}
int peek()
{
    return top->data;
}
void display()
{
    struct list *temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main(int argc, char **argv)
{
    push(566);
    push(766);
    push(966);
    display();
    int d = pop();
    printf("%d\n", d);
    printf("\n");
    display();
    return 0;
}