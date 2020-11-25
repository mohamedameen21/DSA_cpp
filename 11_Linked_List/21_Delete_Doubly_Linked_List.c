#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    int i = 0;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[i];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        last->next = t;
        t->prev = last;
        t->next = NULL;
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

int length(struct Node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        if (first)
        {

            t->next = first;
            first->prev = t;
            first = t;
        }
        else
        {
            t->next = NULL;
            first = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int delete (struct Node *p, int index)
{
    // struct Node *t;
    int i, x;

    if (index < 0 || index > length(p))
    {
        return -1;
    }
    if(index ==0)
    {
        first = first->next;
        if(first)
        {
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for(i=0;i<index;i++)
        {
            p=p->next;
        }
        p->prev->next = p->next;
        if(p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    printf("The Deleted element is %d \n",delete(first,20));
    display(first);
    return 0;
}