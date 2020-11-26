#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly1 = NULL, *poly2 = NULL;

void create1()
{
    struct Node *temp, *last = NULL;
    int num, i;

    printf("Enter Number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp : ");
    for (i = 0; i < num; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &temp->coeff, &temp->exp);
        temp->next = NULL;
        if (poly1 == NULL)
        {
            poly1 = temp;
            last = poly1;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
}

void create2()
{
    struct Node *temp, *last = NULL;
    int num, i;

    printf("Enter Number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp : ");
    for (i = 0; i < num; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &temp->coeff, &temp->exp);
        temp->next = NULL;
        if (poly2 == NULL)
        {
            poly2 = temp;
            last = poly2;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
}

void display(struct Node *p)
{
    while (p)
    {
        if (p->next == NULL)
        {
            if (p->exp == 0)
            {
                // printf("%d",p->coeff);
                printf("%dx%d ", p->coeff, p->exp);
                p = p->next;
            }
        }
        else
        {
            printf("%dx%d + ", p->coeff, p->exp);
            p = p->next;
        }
    }
    printf("\n");
}

long Eval(struct Node *p, int x)
{
    long val = 0;
    while (p)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

void add(struct Node *p, struct Node *q)
{
    while (p && q)
    {
        if (p->exp == q->exp)
        {
            printf("%dx%d + ", p->coeff + q->coeff, p->exp);
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            printf("%dx%d + ", p->coeff, p->exp);
            p = p->next;
        }
        else if (q->exp > p->exp)
        {
            printf("%dx%d + ", q->coeff, q->exp);
            q = q->next;
        }
    }
    if (p)
    {
        while (p)
        {
            printf("%dx%d + ", p->coeff, p->exp);
        }
    }

    if (q)
    {
        while (q)
        {
            printf("%dx%d + ", q->coeff, q->exp);
        }
    }
    printf("\b \b");
    
}

int main()
{
    printf("Ameen");
    printf("\b \b \b");
    
    create1();
    create2();
    display(poly1);
    display(poly2);

    add(poly1, poly2);

    return 0;
}