#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *a;
    int n;
};

void Set(struct Matrix *m, int i, int j, int element)
{
    if (i <= j)
    {
        m->a[j - i] = element;
    }
    if (i > j)
    {
        m->a[m->n + i - j - 1] = element;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i <= j)
    {
        return m.a[j - i];
    }
    if (i > j)
    {
        return m.a[m.n + i - j - 1];
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
            if (i <= j)
            {
                printf("%d ", m.a[j - i]);
            }
            if (i > j)
            {
                printf("%d ", m.a[m.n + i - j - 1]);
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
    m.a = (int *)malloc((2 * m.n - 1) * sizeof(int));

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
    printf("%d", Get(m, 3, 3));
    return 0;
}