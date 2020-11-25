#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *Head = NULL;

void create(int a[], int n)
{
    int i = 0;
    struct Node *temp, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = a[i];
    Head->prev = Head;
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->prev = last;
        temp->next = Head;
        last->next = temp;
        Head->prev = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Head);
    printf("\n");
}

int count(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *temp;
    int i;
    if (Head)
    {

        if (index < 0 || index > count(Head))
        {
            return;
        }
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if (index == 0)
    {
        if (Head == NULL)
        {
            temp->prev = temp;
            temp->next = temp;
            Head = temp;
        }
        else
        {
            temp->next = Head;
            temp->prev = Head->prev;
            Head->prev->next = temp;
            Head->prev = temp;
            Head = temp;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->prev = p;
        temp->next = p->next;
        if (p->next != Head)
        {
            p->next->prev = temp;
        }
        else
        {
            Head->prev = temp;
        }
        p->next = temp;
    }
}

int delete (struct Node *p, int index)
{
    int x,i;
    if (Head == NULL)
    {
        return -1;
    }
    if (index < 0 || index > count(p))
    {
        return-1;
    }
    if(index == 0)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        Head = p->next;
        x = p->data;
        free(p);
    }
    else
    {
        for(i=0;i<index;i++)
        {
            p=p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    
    return x;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    display(Head);
    insert(Head, 5, 8);
    display(Head);
    delete(Head,5);
    display(Head);
    
    return 0;
}
 
//I am Happy I finished by myself sorry for the poor english 
//I think I need to improve my english knowledge and typing skills 
//Ok bye 
