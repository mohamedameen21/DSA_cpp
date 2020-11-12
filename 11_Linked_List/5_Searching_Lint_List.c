#include <stdio.h>
#include <stdlib.h>

//Binary search is not suitable in Linked list

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first;

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

struct Node *Linear_Search(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node *RLinear_Search(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data == key)
    {
        return p;
    }
    return RLinear_Search(p->next, key);
}

int main()
{
    int a[3] = {1, 2, 3};
    create(a, 3);
    display(first);
    struct Node *r;
    r = Linear_Search(first, 3);
    printf("\n%d", r->data);
    r = RLinear_Search(first, 3);
    printf("\n%d\n", r->data);

    display(first);

    printf("\n");
    return 0;
}