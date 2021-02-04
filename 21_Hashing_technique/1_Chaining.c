#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
    {
        *H = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *H[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        H[i] = NULL;
    }

    Insert(H, 12);
    Insert(H, 35);
    Insert(H, 68);
    Insert(H, 14);
    Insert(H, 99);
    Insert(H, 64);
    Insert(H, 34);

    Insert(H, 2);
    Insert(H, 32);

    int key = 64;

    struct Node *temp = Search(H[hash(key)], key);

    printf("%d ", temp->data);

    return 0;
}