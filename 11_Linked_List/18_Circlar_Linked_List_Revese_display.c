#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head;

void create(int a[], int n)
{
    int i = 0;
    struct Node *temp, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = a[i];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void Reversedisplay(struct Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        Reversedisplay(p->next);
        printf("%d ",p->data);
        
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    Reversedisplay(Head);
    return 0;
}