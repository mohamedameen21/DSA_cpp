#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first ;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;  //last is a simple pointer which points to 
    //the struct Node element so we cannot created the memory in dynamic 
    //memory
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Max(struct Node *p)
{
    int m = p->data;
    while (p)
    {
        if(p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
    
}

int RMax(struct Node *p)
{
    int x =0;
    if(p==0)
    {
        return -1;
    }
    x = RMax(p->next);
    if(x>p->data)
    {
        return x;
    }
    else
    {
        return p->data; 
    }
    
}

int main()
{
    int a[] = {3,5,7,10,65,8,12,20};
    create(a,8);
    printf("Max is %d\n",RMax(first));
    return 0;
}