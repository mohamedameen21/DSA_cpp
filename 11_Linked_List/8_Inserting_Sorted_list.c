#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;

void create(int a[], int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Sort_Insert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && x > p->data)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    // int a[] = {10, 20, 30, 40, 50};
    // create(a, 5);
    // Sort_Insert(first, 35);
    // Sort_Insert(first, 5);
    // Sort_Insert(first, 65);

    Sort_Insert(first,55);
    Sort_Insert(first,15);
    display(first);
    printf("\n");
    return 0;
}
