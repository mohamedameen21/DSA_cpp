// Merge two Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
}

int isloop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    while (p != q && q != NULL && p != NULL)
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    }
    // if(p==q)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
    return p == q ? 1 : 0;  //conditional statement
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    //We can also move t1 and t2 using while loop

    t2->next = t1;

    printf("%d\n", isloop(first));

    printf("\n");
    return 0;
}