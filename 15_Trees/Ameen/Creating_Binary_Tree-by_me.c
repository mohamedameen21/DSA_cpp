#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    struct Tree *lchild;
    int data;
    struct Tree *rchild;
};

struct Queue
{
    int front;
    int rear;
    int size;
    struct Tree **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Tree **)malloc(q->size * sizeof(struct Tree *));
}

void enqueue(struct Queue *q, struct Tree *x)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->rear = q->front = 0;
        q->Q[q->rear] = x;
    }
    else if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Tree *dequeue(struct Queue *q)
{
    struct Tree *x = NULL;
    if (q->front == q->rear)
    {
        x = q->Q[q->front];
        q->front = q->rear = -1;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = q->Q[q->front];
        q->front = (q->front + 1) % q->size;
    }
    return x;
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1 && q->rear == -1) ? 1 : 0;
}

void display(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i = q->front;
        while (i != q->rear)
        {
            printf("%d ", q->Q[i]);
            i = (i + 1) % q->size;
        }
        printf("%d ", q->Q[i]);
    }
}

struct Tree *root = NULL;

void Treecreate()
{
    struct Queue q;
    int x;
    create(&q,30);
    printf("Enter the root value: ");
    scanf("%d", &x);
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    struct Tree *p, *t;
    while (!isEmpty(&q))
    {
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}


void Preorder(struct Tree *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Tree *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Tree *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    Treecreate();
    printf("\nPre Order : ");
    Preorder(root);
    printf("\nInorder : ");
    Inorder(root);
    printf("\nPost Order : ");
    Postorder(root);
    return 0;
}