#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int length;
    int array[3];
    struct Node *next;
}*Head;

void create(int a[],int n)
{
    struct Node *temp,*last;
    int i=0,j=0;
    Head = (struct Node *)malloc(sizeof(struct Node)); 
    // Head->array[0] = a[0];
    Head->next = NULL;
    Head->length = 0;
    last = Head;

    for (i = 0; i < n; i++)
    {
        if(j<Head->length)
        {
            last->array[j++] = a[i];
            last->length++;
        }
        else
        {
            struct Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node ));
            j=0;
            temp->length = 0;
            temp->array[j++] = a[i];
            temp->length++;
            last->next = temp;
            temp->next = NULL;
            last = temp;
        }
        
    }
    
}

void display(struct Node *p)
{
    int j=0;
    while (p)
    {
        if(j<p->length)
        {
            printf("%d ",p->array[j++]);
        }
        else
        {
            j=0;
            p=p->next;
        }
        
    }
    
}


int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    create(a,10);
    display(Head);
    return 0;
}