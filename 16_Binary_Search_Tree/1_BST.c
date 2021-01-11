#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key == t->data)
        {
            return;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
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

struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node *RSearch(struct Node *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (key == t->data)
    {
        return t;
    }
    else if (key < t->data)
    {
        return RSearch(t->lchild, key);
    }
    else if (key > t->data)
    {
        return RSearch(t->rchild, key);
    }
}

struct Node *RInsert(struct Node *t, int key)
{
    struct Node *p, *r;
    if (t == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        if (root == NULL)
        {
            root = p;
            return root;
        }
        else
        {
            t = p;
            return t;
        }
    }
    else
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {

            t->lchild = RInsert(t->lchild, key);
        }
        else if (key > t->data)
        {

            t->rchild = RInsert(t->rchild, key);
        }
    }
}

int main()
{
    // Insert(10);
    // Insert(5);
    // Insert(20);
    // Insert(8);
    // Insert(30);

    RInsert(root, 50);
    RInsert(root, 45);
    RInsert(root, 8);
    RInsert(root, 74);
    RInsert(root, 90);
    RInsert(root, 1);
    RInsert(root, 60);

    Inorder(root);
    printf("\n");

    struct Node *s = RSearch(root, 74);
    if (s)
    {
        printf("Element is Found %d\n", s->data);
    }
    else
    {
        printf("Element is not Found\n");
    }

    return 0;
}
