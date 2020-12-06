#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *S = malloc(sizeof(struct Stack));
    //In c the malloc function is automatically typecast
    //we no need to typecast it 
    if (!S)
    {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = (int *)malloc(capacity * sizeof(int));
    if (!S->array)
    {
        return NULL;
    }
    return S;
}

int isEmpty(struct Stack *S)
{
    return (S->top == -1);
}

int size(struct Stack *S)
{
    return (S->top + 1);
}

int isFull(struct Stack *S)
{
    return (S->top == S->capacity - 1);
}

void push(struct Stack *S, int data)
{
    if (isFull(S))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        S->array[++S->top] = data;
    }
}

int pop(struct Stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return (S->array[S->top--]);
    }
}

int peek(struct Stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return (S->array[S->top]);
    }
}

void deleteStack(struct Stack *S)
{
    if (S)
    {
        if (S->array)
        {
            free(S);
        }
    }
}

int main()
{
    int i = 0, capacity = 15;
    struct Stack *stk = createStack(capacity);
    for (size_t i = 1; i <= capacity; i++)
    {
        push(stk, i);
    }
    printf("Top element is %d \n", peek(stk));
    printf("Stack size is %d \n", size(stk));
    printf("Is Stack is Full %d \n",isFull(stk));

    for (size_t i = 0; i < capacity; i++)
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