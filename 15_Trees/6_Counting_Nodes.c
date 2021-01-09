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

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q, 50);
    printf("%d ", p->data);
    enqueue(&q, p);
    while (!isempty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

int count(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
    {
        return y + 1;
    }
}

int countleaf(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (!p->lchild && !p->rchild) //degree 0
    {
        return countleaf(p->lchild) + countleaf(p->rchild) + 1;
    }
    else
    {
        return countleaf(p->lchild) + countleaf(p->rchild);
    }
}

int countnonleaf(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->lchild || p->rchild)  //degree 1 or 2
    {
        return countnonleaf(p->lchild) + countnonleaf(p->rchild) + 1;
    }
    else
    {
        return countnonleaf(p->lchild) + countnonleaf(p->rchild);
    }
}

int main()
{
    Treecreate();
    // printf("\nPre Order : ");
    // Preorder(root);
    // printf("\nPost Order : ");
    // Postorder(root);
    // printf("\nInorder : ");
    // Inorder(root);
    // printf("\nLevel Order : ");
    // Levelorder(root);

    printf("Count %d ", count(root));
    printf("Height %d ", height(root));
    printf("\nLeaf Nodes: %d",countleaf(root));
    printf("\nNon Leaf Nodes: %d",countnonleaf(root));
    return 0;
}