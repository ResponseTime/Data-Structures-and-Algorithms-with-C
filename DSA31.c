#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};

struct tree *create_tree(int data)
{
    struct tree *p;
    p = (struct tree *)malloc(sizeof(struct tree));
    p->left = NULL;
    p->right = NULL;
    p->data = data;
}
int main(int argc, char **argv)
{
    // struct tree *p;
    // p = (struct tree *)malloc(sizeof(struct tree));

    // p->data = 6;

    // struct tree *p1;
    // p1 = (struct tree *)malloc(sizeof(struct tree));
    // p1->left = NULL;
    // p1->right = NULL;
    // p1->data = 11;

    // struct tree *p2;
    // p2 = (struct tree *)malloc(sizeof(struct tree));
    // p2->left = NULL;
    // p2->right = NULL;
    // p2->data = 2;

    // p->left = p1;
    // p->right = p2;

    struct tree *p = create_tree(9);
    struct tree *p1 = create_tree(11);
    struct tree *p2 = create_tree(2);
    p->left = p1;
    p->right = p2;
    return 0;
}