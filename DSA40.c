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
    return p;
}
int search(struct tree *root, int data)
{
    if (root == NULL)
        return -1;
    else if (root->data == data)
    {
        return 1;
    }
    else if (data < root->data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
}
int main(int argc, char **argv)
{
    struct tree *p = create_tree(5);
    struct tree *p1 = create_tree(3);
    struct tree *p2 = create_tree(6);
    struct tree *p3 = create_tree(1);
    struct tree *p4 = create_tree(4);
    p->right = p2;
    p->left = p1;
    p1->right = p4;
    p1->left = p3;
    printf("%d\n", search(p, 45));
    return 0;
}
