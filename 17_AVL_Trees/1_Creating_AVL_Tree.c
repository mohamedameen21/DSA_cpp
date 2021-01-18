#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = (p != NULL && p->lchild != NULL) ? p->lchild->height : 0;
    hr = (p != NULL && p->rchild != NULL) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = (p != NULL && p->lchild != NULL) ? p->lchild->height : 0;
    hr = (p != NULL && p->rchild != NULL) ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
    {
        root = plr;
    }

    return plr;
}

struct Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
    {
        root = prl;
    }
    return prl;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; //we are stating height from 1 onwards
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }
    return p;
}

int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild)
    {
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild)
    {
        p = p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        printf("1 Checking weather Program is executing this statement \n");
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        printf("2 Checking weather Program is executing this statement \n");
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
    {
        printf("3 Checking weather Program is executing this statement \n");
        //We can perform any rotation in llRotation or LRRotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        printf("4 Checking weather Program is executing this statement \n");
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        printf("5 Checking weather Program is executing this statement \n");
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
    {
        printf("6 Checking weather Program is executing this statement \n");
        //We can perform any rotation in RRRotation or RLRotation

        return RRRotation(p);
    }
    return p;
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

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{
    // root = RInsert(root, 10);
    // RInsert(root, 20);
    // RInsert(root, 30);
    // RInsert(root, 25);
    // RInsert(root, 28);
    // RInsert(root, 27);
    // RInsert(root, 5);
    //These elements do can do all kind of rotation

    root = RInsert(root, 9);
    RInsert(root, 5);
    RInsert(root, 10);
    RInsert(root, 0);
    RInsert(root, 6);
    RInsert(root, 11);
    RInsert(root, -1);
    RInsert(root, 1);
    RInsert(root, 2);

    Preorder(root);
    printf("\n");

    Delete(root, 10);

    Preorder(root);
    printf("\n");



    return 0;
}