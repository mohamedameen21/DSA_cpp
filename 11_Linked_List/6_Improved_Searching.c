#include <stdio.h>
#include <stdlib.h>

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

//Two methods to improve the linear Search
//Trasposition - Bringing the element step by step forward
//Move to Head - Bringing the element at the head of the list

//We avoid transposition in linked list

struct Node *Move_Head_Search(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    struct Node *temp;
    int a[] = {3, 4, 7, 10, 25, 8, 32, 2};
    create(a, 8);
    temp = Move_Head_Search(first, 25);
    temp = Move_Head_Search(first, 8);

    if (temp)
    {
        printf("Key is found %d \n", temp->data);
    }
    else
    {
        printf("Key is not found \n");
    }
    display(first);
    printf("\n");

    return 0;
}