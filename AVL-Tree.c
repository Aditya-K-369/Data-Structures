#include <stdlib.h>
#include <stdio.h>
struct NODE
{
    int data, ht;
    struct NODE *left, *right;
};
typedef struct NODE *node;

node createNode(int x)
{
    node temp = (node)malloc(sizeof(struct NODE));
    temp->data = x;
    temp->right = temp->left = NULL;
    return temp;
}

node height(node root)
{
    int lh, rh;
    if (root == NULL)
        return (0);
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}

node balance(node root)
{
    int lh, rh;
    if (root == NULL)
        return (0);
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return (lh - rh);
}

node rotateRight(node x)
{
    node y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}
node rotateLeft(node x)
{
    node y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

node LL(node root)
{
    root = rotateLeft(root);
    return (root);
}
node RR(node root)
{
    root = rotateRight(root);
    return (root);
}
node RL(node root)
{
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
    return (root);
}
node LR(node root)
{
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
    return (root);
}

node inorderInAVL(node root)
{
    if (root != NULL)
    {
        inorderInAVL(root->left);
        printf("%d (%d) ", root->data, balance(root));
        inorderInAVL(root->right);
    }
}

node insert(node root, int x)
{
    if (root == NULL)
    {
        root = createNode(x);
        printf("Successfully inserted.\n");
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
        if (balance(root) == -2)
        {
            if (x > root->right->data)
                root = LL(root);
            else
                root = RL(root);
        }
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
        if (balance(root) == 2)
        {
            if (x < root->right->data)
                root = RR(root);
            else
                root = LR(root);
        }
    }
    else
    {
        printf("ELement %d already exsits.\n", x);
    }

    root->ht = height(root);
    return (root);
}

int main()
{
    int x, op;
    node root = NULL;

    while (1)
    {
        printf("1. Insert 2. Inorder Traversal 3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter an element to be inserted: ");
            scanf("%d", &x);
            root = insert(root, x);
            break;

        case 2:
            if (root == NULL)
            {
                printf("AVL Tree is empty.\n");
            }
            else
            {
                printf("Elements of the AVL tree (in-order traversal): ");
                inorderInAVL(root);
                printf("\n");
            }
            break;

        case 3:
            exit(0);
        }
    }
}
