#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *create(int data)
{
    struct tree *p = (struct tree *)malloc(sizeof(struct tree));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct tree *insert(struct tree *root, int data)
{
    if (root == NULL)
    {
        struct tree *p = (struct tree *)malloc(sizeof(struct tree));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
}
void preOrder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main(int argc, char **argv)
{
    struct tree *root = NULL;
    root = create(1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    preOrder(root);
    return 0;
}