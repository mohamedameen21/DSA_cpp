#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL ,*last;

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void create(int a[], int n)
{
    int i;
    struct Node *t;
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
    printf("\n");
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {

        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insertlast(int x)
{
    
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

int main()
{
    int a[] = {8, 6, 3};
    create(a, 3);
    insert(first, 3, 7);
    display(first);

    insert(first, 0, 1);
    display(first);

    insertlast(30);
    display(first);

    insertlast(287);
    display(first);
    
    insert(first, 1, 78);
    display(first);

    printf("\n");

    return 0;
}