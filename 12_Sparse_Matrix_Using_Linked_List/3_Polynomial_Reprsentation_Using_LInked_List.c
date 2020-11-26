#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create()
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
        if (poly == NULL)
        {
            poly = temp;
            last = poly;
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
            if(p->exp==0)
            {
                printf("%d",p->coeff);
            }
            printf("%dx%d ", p->coeff, p->exp);
            p = p->next;

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

int main()
{
    create();
    display(poly);
    printf("%ld\n", Eval(poly, 1));
    return 0;
}