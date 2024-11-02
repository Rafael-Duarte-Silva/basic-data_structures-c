#include <stdio.h>
#define CAPACITY 10

typedef struct
{
    int numbers[CAPACITY];
    int size;
} queue;

void enqueue(queue *q, int item);
void dequeue(queue *q);

int main(void)
{
    queue numberQueue = {.size = 0};
    for (int i = 0; i < CAPACITY; i++)
    {
        enqueue(&numberQueue, i);
    }

    dequeue(&numberQueue);
    enqueue(&numberQueue, 7);

    // for display only
    for (int i = 0; i < numberQueue.size; i++)
    {
        printf("%i ", numberQueue.numbers[i]);
    }
    printf("\n");

    return 0;
}

void enqueue(queue *q, int item)
{
    if (q->size <= CAPACITY)
    {
        q->numbers[q->size] = item;
        q->size++;
    }
}

void dequeue(queue *q)
{
    if (q->size > 0)
    {
        for (int i = 0; i < q->size - 1; i++)
        {
            q->numbers[i] = q->numbers[i + 1];
        }
        q->size--;
    }
}