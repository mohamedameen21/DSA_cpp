#include <stdio.h>
#include <stdlib.h>

//Hello actually i am using comments to check how long can i write code in one line and it is good to see like this I like it

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

int Delete(struct Node *p, int index)
{
    struct Node *q = 0;
    int x = -1, i;

    if (index < 1 || index > count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int check_Sorted(struct Node *p)
{
    printf("%d\n", p->next->data);
    int x = -65536;
    while (p)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void remove_duplicate(struct Node *p)
{
    struct Node *q = p->next; //p as a tail pointer
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    printf("\n");

    // int a[] = {10,10,10, 20, 20, 20, 30, 40,10, 40, 40, 50};
    // int a[] = {10,10,10, 20, 20, 20, 30, 40,10, 40, 40, 50};
    int a[] = {10,10,10};
    create(a, 3);

    remove_duplicate(first);
    // printf("\n");
    display(first);

    printf("\n\n");
    return 0;
}
