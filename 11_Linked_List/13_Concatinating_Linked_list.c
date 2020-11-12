#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL, *second = NULL, *third = NULL;

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

void create2(int a[], int n)
{
    int i;
    struct Node *temp, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;

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
    printf("\n");
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

void concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

int main()
{
    printf("\n");

    int a[] = {10, 20, 30};
    int b[] = {5, 15, 25};

    create(a, 3);
    create2(b, 3);

    concat(second, first);
    printf("Concatinated List \n");
    display(third);

    printf("\n");
    return 0;
}