#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *stack;
};
void stack_init(struct stack *stack, int size)
{
    stack->size = size;
    stack->top = -1;
    stack->stack = (int *)malloc(sizeof(int) * size);
}
void push(struct stack *stack, int data)
{
    if (stack->top == stack->size - 1)
    {
        printf("stack overflow");
    }
    else
    {
        stack->stack[++stack->top] = data;
    }
}

void display(struct stack *stack)
{
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->stack[i]);
    }
}
int pop(struct stack *stack)
{
    if (stack->top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        return stack->stack[stack->top--];
    }
}
int peek(struct stack *stack)
{
    return stack->stack[stack->top];
}
void is_empty(struct stack *stack)
{
    if (stack->top == -1)
    {
        printf("stack empty\n");
    }
    else
    {
        printf("stack not empty\n");
    }
}
void is_full(struct stack *stack)
{
    if (stack->top == stack->size - 1)
    {
        printf("stack full\n");
    }
    else
    {
        printf("stack not full\n");
    }
}
// push --
// pop --
// peek --
// is_empty --
// is_full --
int main(int argc, char **argv)
{
    struct stack stack;
    stack_init(&stack, 4);
    is_empty(&stack);
    push(&stack, 100);
    push(&stack, 200);
    push(&stack, 300);
    push(&stack, 400);
    is_full(&stack);
    int a = pop(&stack);
    printf("a = %d\n", a);
    int f = peek(&stack);
    printf("f = %d\n", f);
    display(&stack);
    is_empty(&stack);
    is_full(&stack);
    return 0;
}