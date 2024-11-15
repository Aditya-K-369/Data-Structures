#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node *node;

node newNode(ele)
{
    node temp = (node)malloc(sizeof(struct node));
    temp->data = ele;
    temp->left = temp->right = NULL;
    return temp;
}

node insert(node root, int ele)
{
    if (root == NULL)
    {
        root = newNode(ele);
        return root;
    }
    if (ele < root->data)
    {
        root->left = insert(root->left, ele);
    }
    else if (ele > root->data)
    {
        root->right = insert(root->right, ele);
    }
    return root;
}
void inorder(node Node)
{
    if (Node != NULL)
    {
        inorder(Node->left);
        printf("%d\n", Node->data);
        inorder(Node->right);
    }
}
void preorder(node Node)
{
    if (Node != NULL)
    {
        printf("%d\n", Node->data);
        preorder(Node->left);
        preorder(Node->right);
    }
}
void postorder(node Node)
{
    if (Node != NULL)
    {
        postorder(Node->left);
        postorder(Node->right);
        printf("%d\n", Node->data);
    }
}

void main()
{
    node root = NULL;
    int data, choice;
    while (1)
    {
        printf("1.Insert Node\n2.Delete Node\n3.Search for node");
        printf("\n4.inorder\n5.preorder\n6.postorder\n7.exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            // printf("Enter the element to delete:");
            // scanf("%d", &data);
            // delete (data);
            break;
        case 3:
            preorder(root);
            // printf("Enter the element to search in tree");
            // scanf("%d", &data);
            // search(data);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            preorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            exit(0);
        default:
            exit(0);
        }
    }
}