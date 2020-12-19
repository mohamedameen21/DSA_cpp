#include <stdio.h>
#include <stdlib.h>

//This method is mostly used in operating system

struct Queue
{
    int size;
    int front;
    int rear;
    char *Q;
};

struct Queue Q1, Q2, Q3;

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (char *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, char x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is Full \n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

char dequeue(struct Queue *q)
{
    char x = 'x';
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%c ", q.Q[i]);
    }
    // printf("\n");
}

int priority(char x)
{
    if ((x == 'A' || x == 'a') ||(x == 'B' || x == 'b') || (x == 'C' || x == 'c'))
    {
        return 3;
    }
    else if ((x == 'D' || x == 'd') || (x == 'E' || x == 'e') || (x == 'F' || x == 'f'))
    {
        return 2;
    }
    else if ((x == 'G' || x == 'g') || (x == 'H' || x == 'h') || (x == 'I' || x == 'i'))
    {
        return 1;
    }
}

void passEnqueue(char x)
{
    int p;
    p = priority(x);
    if (p == 3)
    {
        enqueue(&Q1, x);
        return;
    }
    else if (p == 2)
    {
        enqueue(&Q2, x);
        return;
    }
    else if (p == 1)
    {
        enqueue(&Q3, x);
        return;
    }
    else
    {
        printf("Invalid Character\n");
    }
}

int isEmpty(struct Queue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue q)
{
    if (q.rear == q.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void passdequeue()
{
    if (!isEmpty(Q1))
    {
        dequeue(&Q1);
    }
    else if (!isEmpty(Q2))
    {
        dequeue(&Q2);
    }
    else
    {
        dequeue(&Q3);
    }
}

void passDisplay()
{
    if (!isEmpty(Q1))
    {
        Display(Q1);
    }
    if (!isEmpty(Q2))
    {
        Display(Q2);
    }
    if(!isEmpty(Q3))
    {
        Display(Q3);
    }
    printf("\n");
}

int main()
{
    create(&Q1, 5);
    create(&Q2, 5);
    create(&Q3, 5);

    passEnqueue('A');
    passEnqueue('D');
    passEnqueue('H');
    passDisplay();
    passdequeue();
    passdequeue();
    passDisplay();

    return 0;
}