#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    stack->stack[++stack->top] = data;
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

    return stack->stack[stack->top--];
}
int peek(struct stack *stack)
{
    return stack->stack[stack->top];
}
int is_empty(struct stack *stack)
{
    if (stack->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
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
int prec(char c)
{
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '/' || c == '*')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
char *infix_to_postfix(char *inf, int len)
{
    struct stack stack;
    stack_init(&stack, len + 1);
    char *post = (char *)malloc((len + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (inf[i] != '\0')
    {
        if (inf[i] != '-' && inf[i] != '*' && inf[i] != '+' && inf[i] != '/')
        {
            post[j] = inf[i];
            j++;
            i++;
        }
        else
        {
            if (prec(inf[i]) > prec(peek(&stack)))
            {
                push(&stack, inf[i]);
                i++;
            }
            else
            {
                post[j] = pop(&stack);
                j++;
            }
        }
    }
    while (stack.top != -1)
    {
        post[j] = pop(&stack);
        j++;
    }
    post[j] = '\0';
    return post;
}
int main(int argc, char **argv)
{
    char *inf = "X-Y/Z-K*D";
    printf("%s", infix_to_postfix(inf, strlen(inf)));
    return 0;
}

// X - Y / Z - K *D infix to postfix
// XYZ/-KD*-
