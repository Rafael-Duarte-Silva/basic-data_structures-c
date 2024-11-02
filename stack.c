#include <stdio.h>
#define CAPACITY 10

typedef struct
{
    int numbers[CAPACITY];
    int size;
} stack;

void push(stack *s, int item);
void pop(stack *s);

int main(void)
{
    stack numberStack = {.size = 0};
    for (int i = 0; i < CAPACITY; i++)
    {
        push(&numberStack, i);
    }

    pop(&numberStack);
    push(&numberStack, 7);

    // for display only
    for (int i = 0; i < numberStack.size; i++)
    {
        printf("%i ", numberStack.numbers[i]);
    }
    printf("\n");

    return 0;
}

void push(stack *s, int item)
{
    if (s->size <= CAPACITY)
    {
        s->numbers[s->size] = item;
        s->size++;
    }
}

void pop(stack *s)
{
    if (s->size > 0)
    {
        s->size--;
    }
}