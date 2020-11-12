#include <stdio.h>
#include <stdlib.h>

//There are two methods for reversing a linked list
//1)reversing elements
//2)reversing links

//Always use the 2nd method because if the node data is more we have to
//copy all the node data values to another . It is not recommended
//We can simply change by reversing the links

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

//Reversing using the elements in the node

void revese_using_array(struct Node *p)
{
    int *a;
    a = (int *)malloc(sizeof(int) * count(p));
    struct Node *q = p;
    int i = 0;
    while (q != NULL)
    {
        a[i++] = q->data;
        q = q->next;
        // i++;
    }
    i--;
    q = p;
    while (q != NULL)
    {
        q->data = a[i--];
        q = q->next;
        // i--;
    }
}

//Reversing by editing the links

void reverse_by_links(struct Node *p)
{
    struct Node *r = NULL;
    struct Node *q = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Reversing by editing the links through recursion

void revese_recursion(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        revese_recursion(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    printf("\n");

    int a[] = {2, 4, 6, 8, 10, 12};
    create(a, 6);

    revese_using_array(first);
    reverse_by_links(first);
    revese_recursion(0, first);
    display(first);

    printf("\n");
    return 0;
}
