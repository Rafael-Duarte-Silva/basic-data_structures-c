#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

node *createNode(int item);
void insertNode(node **root, int item);
void searchNode(node *root, int item);

int main(void)
{
    node *tree = NULL;
    insertNode(&tree, 4);
    insertNode(&tree, 7);
    insertNode(&tree, 6);
    insertNode(&tree, 5);
    insertNode(&tree, 8);
    insertNode(&tree, 1);

    // for display only
    searchNode(tree, 5);
    searchNode(tree, 10);

    return 0;
}

node *createNode(int item)
{
    node *n = (node *)malloc(sizeof(node));

    n->number = item;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertNode(node **root, int item)
{
    node *n = createNode(item);

    if (*root == NULL)
    {
        *root = n;
        return;
    }

    node *ptr = *root;
    while (ptr != NULL)
    {
        if (item < ptr->number)
        {
            if (ptr->left == NULL)
            {
                ptr->left = n;
                break;
            }
            ptr = ptr->left;
        }
        else if (item > ptr->number)
        {
            if (ptr->right == NULL)
            {
                ptr->right = n;
                break;
            }
            ptr = ptr->right;
        }
    }
}

void searchNode(node *root, int item)
{
    if (root == NULL)
    {
        return;
    }

    node *ptr = root;
    while (ptr != NULL)
    {
        if (item == ptr->number)
        {
            printf("Number %i has been found\n", item);
            return;
        }
        else if (item < ptr->number)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }

    printf("Number %i not found\n", item);
}