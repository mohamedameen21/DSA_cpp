#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *a;
    int n;
};

void Set(struct Matrix *m, int i, int j, int element)
{
    // if(i-j>=-1 && i-j <=1)
    // {
    //     a[]
    // }

    if (i - j == 1)
    {
        m->a[i - 2] = element;
    }
    if (i - j == 0)
    {
        m->a[(m->n - 1) + i - 1] = element;
    }
    if (i - j == -1)
    {
        m->a[(m->n - 1) + (m->n) + i - 1] = element;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i - j == 1)
    {
        return m.a[i - 2];
    }
    if (i - j == 0)
    {
        return m.a[(m.n - 1) + i - 1];
    }
    if (i - j == -1)
    {
        return m.a[(m.n - 1) + (m.n) + i - 1];
    }
    else
    {
        return 0;
    }
    
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i - j == 1)
            {
                printf("%d ", m.a[i - 2]);
            }
            else if (i - j == 0)
            {
                printf("%d ", m.a[(m.n - 1) + i - 1]);
            }
            else if (i - j == -1)
            {
                printf("%d ", m.a[(m.n - 1) + m.n + i - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("Enter the dimension: ");
    scanf("%d", &m.n);
    m.a = (int *)malloc((3 * m.n - 2) * sizeof(int));
    int i, j, x;
    printf("Enter all elements\n");
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }

    printf("\n\n");
    Display(m);

    printf("\n\n");
    printf("%d",Get(m,3,3));
    return 0;
}