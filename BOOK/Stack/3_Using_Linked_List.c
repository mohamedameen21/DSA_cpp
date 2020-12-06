#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

typedef struct Stack
{
    struct ListNode *top;
} Stack;

struct Stack *createStack()
{
    struct Stack *stk;
    stk = malloc(sizeof(Stack));
    stk->top = NULL;
    return stk;
}

void push(Stack *stk, int data)
{
    struct ListNode *temp;
    temp = malloc(sizeof(struct ListNode));
    if (!temp)
    {
        printf("\nStack Overflow\n");
        return;
    }
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}

int isEmpty(Stack *stk)
{
    return (stk->top == NULL);
}

int isFull(Stack *stk)
{
    Stack *temp = NULL;
    temp = malloc(sizeof(Stack));
    if (!temp)
    {
        return 1;
    }
    return 0;
}

int size(Stack *stk)
{
    int count = 0;
    struct ListNode *p = stk->top;
    if (isEmpty(stk))
    {
        return 0;
    }
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int pop(Stack *stk)
{
    if (isEmpty(stk))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    int data;
    struct ListNode *temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free(temp);
    return data;
}

int peek(Stack *stk)
{
    if (isEmpty(stk))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return stk->top->data;
}

void deleteStack(Stack *stk)
{
    struct ListNode *temp, *p;
    p = stk->top;
    while (p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    free(stk);
}

void display(Stack *stk)
{
    struct ListNode *p = stk->top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Stack *stk = createStack();
    for (size_t i = 1; i <= 10; i++)
    {
        push(stk, i);
    }
    printf("Top element is %d \n", peek(stk));
    printf("Stack size is %d \n", size(stk));
    printf("Is Stack is Full %d \n", isFull(stk));
    display(stk);

    for (size_t i = 1; i <= 10; i++)
    {
        printf("Poped element is %d \n", pop(stk));
    }
    if (isEmpty(stk))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is Ful\n");
    }
    deleteStack(stk);

    return 0;
}