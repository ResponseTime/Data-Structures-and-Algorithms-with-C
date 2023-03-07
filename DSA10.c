#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *tail;
void add(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        struct node *newtemp = head;
        while (newtemp->next != NULL)
        {
            newtemp = newtemp->next;
        }
        newtemp->next = temp;
        tail = temp;
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
//----------------------------------------------------------------
void insert_last(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}
// insert(i,data)
void insert(int index, int data)
{
    int i = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *ap = head;
    struct node *prev = NULL;
    while (ap->next != NULL)
    {
        prev = ap;
        ap = ap->next;
        i++;
        if (i == index)
        {
            break;
        }
    }
    if (ap->next == NULL)
    {
        insert_last(data);
        return;
    }
    temp->next = prev->next;
    prev->next = temp;
}
// insertfirst()
void insert_first(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head = temp;
}
// insertlast()
// deletefirst()
void delete_first()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}
// deletelast()
void delete_last()
{
    struct node *temp = head;
    struct node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    tail = prev;
    free(temp);
}
// deleteindex(i)
void deleteindex(int index)
{
    struct node *temp = head;
    struct node *prev = head;
    int i = 0;
    if (index == 0)
    {
        delete_first();
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
        i++;
        if (i == index)
        {
            break;
        }
    }
    if (temp->next == NULL)
    {
        delete_last();
        return;
    }
    prev->next = temp->next;
    free(temp);
}
// reverse()
void reverse()
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(int argc, char **argv)
{
    add(1);
    add(2);
    add(232);
    insert(4, 666);
    insert_first(999);
    insert_last(1000);
    delete_first();
    delete_first();
    delete_last();
    deleteindex(0);
    reverse();
    display();
    return 0;
}