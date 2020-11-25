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
    int i=0;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[i];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node ));
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
        printf("%d ",p->data);
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
        p= p->next;
    }
    return length;
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    printf("\nLength is %d : \n",length(first));
    display(first);
    return 0;
}