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

int height(struct Node *p)
{
    int left, right, h;
    if (p == NULL)
    {
        return 0;
    }
    left = height(p->lchild);
    right = height(p->rchild);
    if (left > right)
    {
        h = 1 + left;
    }
    else
    {
        h = 1 + right;
    }
    return h;
}

int Delete(int key)
{
    struct Node *current = root;
    struct Node *parent = NULL;
    int r = 0;
    while (current != NULL)
    {
        if (key == current->data)
        {
            printf("The Key is Found Deletion Process is going on\n");
            break;
        }
        else if (key < current->data)
        {
            parent = current;
            current = current->lchild;
        }
        else if (key > current->data)
        {
            parent = current;
            current = current->rchild;
        }
        else
        {
            printf("The key does not exits \n");
            return 0;
        }
    }
    if (current != NULL)
    {
        if (current->lchild == NULL && current->rchild == NULL)
        {
            if (current->data < parent->data)
            {
                parent->lchild = NULL;
                r = current->data;
                free(current);
            }
            else if (current->data > parent->data)
            {
                parent->rchild = NULL;
                r = current->data;
                free(current);
            }
            return r;
        }
        else if (current->lchild != NULL && current->rchild != NULL)
        {
            struct Node *p, *pp = current;
            int r = 0;
            if (height(current->lchild) >= height(current->rchild))
            {
                p = current->lchild;
                while (p)
                {
                    if (p->rchild == NULL)
                    {
                        break;
                    }
                    pp = p;
                    p = p->rchild;
                }
                r = current->data;
                current->data = p->data;
                if (pp == current)
                {
                    current->lchild = p->lchild;
                    free(p);
                }
                else
                {
                    pp->rchild = p->lchild;
                    free(p);
                }
            }
            else
            {
                p = current->rchild;
                while (p)
                {
                    if (p->lchild == NULL)
                    {
                        break;
                    }
                    pp = p;
                    p = p->lchild;
                }
                r = current->data;
                current->data = p->data;
                if (pp == current)
                {
                    current->rchild = p->rchild;
                    free(p);
                }
                else
                {
                    pp->lchild = p->rchild;
                    free(p);
                }
            }

            return r;
        }
        else if (current->lchild != NULL || current->rchild != NULL)
        {
            if (current->data < parent->data)
            {
                if (current->lchild != NULL)
                {
                    parent->lchild = current->lchild;
                    r = current->data;
                    current->lchild = NULL;
                    free(current);
                }
                else
                {
                    parent->lchild = current->rchild;
                    r = current->data;
                    current->rchild = NULL;
                    free(current);
                }
                return r;
            }
            else
            {
                if (current->lchild != NULL)
                {
                    parent->rchild = current->lchild;
                    r = current->data;
                    current->lchild = NULL;
                    free(current);
                }
                else
                {
                    parent->rchild = current->rchild;
                    r = current->data;
                    current->rchild = NULL;
                    free(current);
                }
                return r;
            }
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

    // RInsert(root, 50);
    // RInsert(root, 45);
    // RInsert(root, 8);
    // RInsert(root, 74);
    // RInsert(root, 90);
    // RInsert(root, 1);
    // RInsert(root, 60);
    // RInsert(root, 48);
    // RInsert(root, 46);
    // RInsert(root, 55);
    // RInsert(root, 58);
    // RInsert(root, 95);
    // RInsert(root, 93);
    // RInsert(root, 100);

    RInsert(root,50);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,30);

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

    printf("The deleted element is %d \n", Delete(30));
    Inorder(root);

    printf("\nHeight of the tree is %d\n", height(root));

    return 0;
}
