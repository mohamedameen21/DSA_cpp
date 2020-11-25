#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int Middleele(struct Node *p)
{
    int x;
    struct Node *q = p = first;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }

        if (q)
        {
            p = p->next;
        }
    }
    x = p->data;
    return x;
}

int main()
{
    int a[] = {3, 5, 7, 10, 15, 23, 87, 90};
    create(a, 8);
    display(first);
    printf("\nThe middle element of the list is %d ", Middleele(first));

    return 0;
}