#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct Queue *q, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Queue));
    if (t == NULL)
    {
        printf("Queue is Full\n");
    }
    t->data = x;
    t->next = NULL;
    if (q->front == NULL)
    {
        q->front = q->rear = t;
    }
    else
    {
        q->rear->next = t;
        q->rear = t;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    struct Node *t;

    if (q->front == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        x = q->front->data;
        t = q->front;
        q->front = q->front->next;
        free(t);
    }
    return x;
}

int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};
    struct Queue *q;
    q->front = q->rear = NULL;

    printf("%d ", i);
    visited[i] = 1;
    enqueue(q, i);

    while (!isEmpty(q))
    {
        i = dequeue(q);
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 3, 7);

    int a = 2147483647;
    printf("\n%d ",a);

    return 0;
}