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
void post_order(struct tree *node)
{
    if (node == NULL)
        return;
    post_order(node->left);
    post_order(node->right);
    printf("%d ", node->data);
}
int main(int argc, char **argv)
{
    struct tree *root = create_tree(4);
    struct tree *l1 = create_tree(1);
    struct tree *r1 = create_tree(6);
    struct tree *l2 = create_tree(5);
    struct tree *r2 = create_tree(6);
    struct tree *l3 = create_tree(2);
    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = l3;
    post_order(root);
    return 0;
}