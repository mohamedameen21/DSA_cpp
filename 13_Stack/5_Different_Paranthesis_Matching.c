//Application of Stack
// 1)Paranthesis Matching

//To find whether the paranthesis is balanced or not
// ((a+b)*(c-d))

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    char data;
    struct Stack *next;
} *top = NULL;

void push(char x)
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

char pop()
{
    char x = -1;
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

char peek(int index)
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

char stacktop()
{
    if (top != NULL)
    {
        return top->data;
    }
    return -1;
}

int isBalance(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' && top->data == '(')
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
        else if (exp[i] == ']' && top->data == '[')
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
        else if (exp[i] == '}' && top->data == '{')
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
        else
        {
            return 0;
        }
        
    }
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "{([a+b]*[c-d])/e}";
    printf("%d ", isBalance(exp));
    return 0;
}