#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
};

int isempty(struct Queue q)
{
    return q.rear == q.front;
}

//Creating Stack

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

// struct Stack st;

void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->S[++st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *top(struct Stack s)
{
    if (s.top == -1)
    {
        return NULL;
    }
    else
    {
        return s.S[s.top];
    }
}

//Creating Tree

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter the root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void IPreorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 50);

    while (p || !isEmpty(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 50);

    while (p || !isEmpty(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);

            p = p->rchild;
        }
    }
}

// void IPostorder(struct Node *p)
// {
//     struct Stack stk;
//     long int temp;
//     Stackcreate(&stk, 50);

//     while (p || !isEmpty(stk))
//     {
//         if (p)
//         {
//             push(&stk, p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = (int)pop(&stk);
//             if (temp > 0)
//             {
//                 push(&stk,(struct Node *(-temp)));
//                 temp = ((struct Node *)temp)->rchild;
//             }
//             else
//             {
//                 printf("%d ", ((struct Node *)temp)->data);
//             }
//         }
//     }
// }

void postOrder(struct Node *root) //From Book
{
    struct Node *previous = NULL;
    struct Stack stk;
    Stackcreate(&stk, 50);
    do
    {
        while (root != NULL)
        {
            push(&stk, root);
            root = root->lchild;
        }
        while (root == NULL && !isEmpty(stk))
        {
            root = top(stk);
        }
        if (root->rchild == NULL || root->rchild == previous)
        {
            printf("%d ", root->data);
            pop(&stk);
            previous = root;
            root = NULL;
        }
        else
        {
            root = root->rchild;
        }

    } while (!isEmpty(stk));
}

//Post order traversal
void func(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 50);
    while (1)
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            if (isEmpty(stk))
            {
                break;
            }
            else
            {
                if (top(stk)->rchild == NULL)
                {
                    p = pop(&stk);
                    printf("%d ", p->data);
                    while (p == top(stk)->rchild)
                    {
                        printf("%d ", top(stk)->data);
                        p = pop(&stk);
                        if (isEmpty(stk))
                        {
                            break; 
                        }
                    }
                }
                if (!isEmpty(stk)) 
                {
                    p = top(stk)->rchild;
                }
                else
                {
                    p = NULL;
                }
            }
        }
    }
}

int main()
{
    Treecreate();
    // printf("\nPre Order : ");
    // Preorder(root);
    // printf("\nPost Order : ");
    // printf("\nInorder : ");
    // Inorder(root);
    // Postorder(root);

    printf("\nPostorder ");
    func(root);

    printf("Hello World");


    return 0;
}