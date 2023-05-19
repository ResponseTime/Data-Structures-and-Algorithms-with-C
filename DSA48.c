#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
    int height;
};
int getHeight(struct tree *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
int balanceFactor(struct tree *r)
{
    if (r == NULL)
    {
        return 0;
    }
    return getHeight(r->left) - getHeight(r->right);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
struct tree *rightRotate(struct tree *r)
{
    struct tree *x = r->left;
    struct tree *y = x->right;
    x->right = r;
    r->left = y;

    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
struct tree *leftRotate(struct tree *root)
{
    struct tree *x = root->right;
    struct tree *y = x->left;
    x->left = root;
    x->right = y;
    return x;
}
struct tree *create_tree(int data)
{
    struct tree *p;
    p = (struct tree *)malloc(sizeof(struct tree));
    p->left = NULL;
    p->right = NULL;
    p->data = data;
    p->height = 1;
    return p;
}
struct tree *insert(struct tree *node, int k)
{
    if (node == NULL)
    {
        return (create_tree(k));
    }
    if (k < node->data)
    {
        node->left = insert(node->left, k);
    }
    else if (k > node->data)
    {
        node->right = insert(node->right, k);
        return node;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = balanceFactor(node);
    if (bf > 1 && k < node->left->data)
    {
        return rightRotate(node);
    }
    if (bf < -1 && k > node->right->data)
    {
        return leftRotate(node);
    }
    if (bf > 1 && k > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && k < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(struct tree *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}
int main(int argc, char **argv)
{
    struct tree *root = NULL;
    root = insert(root, 19);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 5);
    inorder(root);
    return 0;
}