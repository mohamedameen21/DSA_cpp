#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
} *top = NULL;

void push(int x)
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));

    if (t == NULL)
    {
        printf("Stack is Full\n");
    }
    else
    {

        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        struct Stack *p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display()
{
    struct Stack *p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isEmpty()
{
    return top ? 0 : 1;
}

int isFull()
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek(int index)
{
    struct Stack *p = top;

    int i;
    for (i = 0; p != NULL && i < index - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    return -1;
}

int stacktop()
{
    if (top != NULL)
    {
        return top->data;
    }
    return -1;
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("The deleted element is %d \n", pop());
    printf("The value is %d \n", peek(1));
    // pop();
    // pop();
    printf("The value of stack top is %d\n", stacktop());
    display();

    return 0;
}