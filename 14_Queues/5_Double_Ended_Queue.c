#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void Enqueue_From_Rear(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
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

void Enqueue_From_Front(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
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
            t->next = front;
            front = t;
        }
    }
}

int Dequeue_From_Front()
{
    int x = -1;
    struct Node *t;
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

int Dequeue_From_Rear()
{
    int x = -1;
    struct Node *t, *f;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        t = rear;
        f = front;
        while (f->next != rear)
        {
            f = f->next;
        }
        rear = f;
        rear->next = NULL;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = front;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Enqueue_From_Front(10);
    Enqueue_From_Front(20);
    Enqueue_From_Front(30);
    Enqueue_From_Front(40);
    Dequeue_From_Rear();
    Display();
    return 0;
}