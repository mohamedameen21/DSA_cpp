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

int count(struct Node *p)
{
    int count = 0;
    while (p) // while(p!=null)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Rcount(struct Node *p)
{
    if(p==0)
    {
        return 0;
    }
    return 1+count(p->next);
}

int Sum(struct Node *p)
{
    int s=0;
    while (p)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if(p==0)//ij(p!=null)
    {
        return 0;
    }
    return Rsum(p->next) +p->data;
}

int main()
{
    int a[] = {3, 5, 7, 10, 15};
    create(a, 5);
    printf("Length = %d\n",count(first));
    printf("Length = %d\n", Rcount(first));
    printf("Sum = %d\n",Sum(first));
    printf("Sum = %d\n",Rsum(first));

    return 0;
}