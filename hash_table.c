#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CAPACITY 26

typedef struct node
{
    char *key;
    int number;
    struct node *next;
} node;

node *createNode(node *list[], char *key, int item);
void insertNode(node *list[], char *key, int item);
unsigned int hash(const char *WORD);

int main(void)
{
    node *list[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        char temp = 65 + i;

        list[i] = NULL;
        insertNode(list, &temp, i);
    }

    // for display only
    node **ptr = list;
    for (int i = 0; i < CAPACITY; i++)
    {
        while (ptr[i] != NULL)
        {
            printf("%i ", ptr[i]->number);
            ptr[i] = ptr[i]->next;
        }
    }
    printf("\n");

    return 0;
}

node *createNode(node *list[], char *key, int item)
{
    node *n = (node *)malloc(sizeof(node));

    n->key = key;
    n->number = item;
    n->next = list[hash(key)];
    return n;
}

void insertNode(node *list[], char *key, int item)
{
    node *n = createNode(list, key, item);

    list[hash(key)] = n;
}

unsigned int hash(const char *WORD)
{
    return toupper(WORD[0]) - 'A';
}