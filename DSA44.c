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
void inorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
struct tree *inordPre(struct tree *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct tree *delete(struct tree *root, int k)
{
    struct tree *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (root->data > k)
    {
        root->left = delete (root->left, k);
    }
    else if (root->data < k)
    {
        root->right = delete (root->right, k);
    }
    else
    {
        ipre = inordPre(root);
        root->data = ipre->data;
        root->left = delete (root->left, ipre->data);
    }
    return root;
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
    delete (p, 5);
    inorder(p);
    return 0;
}
