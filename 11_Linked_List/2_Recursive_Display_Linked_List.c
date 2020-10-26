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
    if(p!= NULL)
    {
        printf("%d ",p->data);
        display(p->next);
    }
}

void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        Rdisplay(p->next);
        printf("%d ", p->data);
    }
}

int main()
{
    int a[] = {3, 5, 7, 10, 15};
    create(a, 5);
    display(first);
    printf("\n\n");
    Rdisplay(first);
    return 0;
}