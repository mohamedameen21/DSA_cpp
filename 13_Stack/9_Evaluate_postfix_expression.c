//precedences and associativity are ment for paranthezitation
//They dont decide which will execute first
//compiler will no execute the infix form
//if the infix form is given it will implicitly convert the infix to postfix form

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Eval(char *postfix)
{
    int i = 0, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isoperand(postfix[i]))
        {
            push(postfix[i] - '0');
            // push(postfix[i] - 48); both are same

        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char postfix[] = "234*+82/-";
    printf("Result is %d \n ",Eval(postfix));
    return 0;
}