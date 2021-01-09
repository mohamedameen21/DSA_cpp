#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
    if (t == NULL)
    {
        printf("Queue and Heap is Full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Queue *t;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Queue *p;
    p = front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

