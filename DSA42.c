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
void insert(struct tree *root, int data)
{
    struct tree *p = create_tree(data);
    struct tree *temp = root;
    struct tree *prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        if (p->data < temp->data)
        {

            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (p->data == root->data)
    {
        return;
    }
    else if (p->data < prev->data)
    {
        prev->left = p;
    }
    else
    {
        prev->right = p;
    }
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
    inorder(p);
    insert(p, 2);
    printf("\n");
    inorder(p);
    return 0;
}
