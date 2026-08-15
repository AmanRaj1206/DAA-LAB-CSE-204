#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node *findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node has no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Node has only right child
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Node has only left child
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        else
        {
            struct node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int N, value, deleteValue;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    printf("Enter %d elements:\n", N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal before deletion:\n");
    inorder(root);

    printf("\nEnter element to delete: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("Inorder traversal after deletion:\n");
    inorder(root);

    printf("\n");

    return 0;
}
