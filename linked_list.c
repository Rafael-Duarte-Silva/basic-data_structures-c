#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

node *createNode(node *list, int item);
void insertNode(node **list, int item);

int main(void)
{
    node *list = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertNode(&list, i);
    }

    // for display only
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i ", ptr->number);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}

node *createNode(node *list, int item)
{
    node *n = (node *)malloc(sizeof(node));

    n->number = item;
    n->next = list;
    return n;
}

void insertNode(node **list, int item)
{
    node *n = createNode(*list, item);

    *list = n;
}