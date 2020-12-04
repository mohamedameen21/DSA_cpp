//Application of Stack
// 1)Paranthesis Matching

//To find whether the paranthesis is balanced or not
// ((a+b)*(c-d))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
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

int Instackpre(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    else if (x == ')')
    {
        return -1;
    }

    else
    {
        return 0;
    }
}

int Outstackpre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }

    else
    {
        return 0;
    }
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

char *IntoPost(char *infix)
{
    char *postfix;
    int len = (int)strlen(infix) + 2;
    postfix = (char *)malloc(len * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (Outstackpre(infix[i]) > Instackpre(top->data))
            {
                push(infix[i++]);
            }
            else
            {

                if (top->data == ')' || top->data == '(')
                {
                    pop();
                    // infix[i++];
                }
                else
                {
                    postfix[j++] = pop();
                    // infix[i++];
                }
                if(top->data == '#')
                {
                    infix[i++];
                }
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    // postfix[j] = '\0';
    //To convert the character to string we append \0 operator
    //here we use # to push a symbol intialy inside the stack so postfix also
    //contains that # symbol at last
    //I have an idea we can replace that # symbol to \0 so that the answer is clear
    postfix[--j] = '\0';
    return postfix;
}

int main()
{
    char *exp = "((a+b)*c)-d^e^f";
    //postfix = ab+c*def^^-
    // char *exp = "a+b*(c^d-e)^(f+g*h)-i";
    // abcd^e-fgh*+^*+i-
    push('#');
    char *posfix = IntoPost(exp);
    printf("%s ", posfix);
    return 0;
}