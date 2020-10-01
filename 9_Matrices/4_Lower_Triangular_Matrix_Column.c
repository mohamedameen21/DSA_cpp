#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *a;
    int n;
};

void Set(struct Matrix *m, int i, int j, int element)
{
    if (i >= j)
    {
        m->a[m->n*(j-1) + (j-2)*(j-1)/2 + i-j] = element;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.a[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
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
            if (i >= j)
            {
                printf("%d ", m.a[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
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
    int i,j;
    int x;
    printf("Enter the dimension: ");
    scanf("%d", &m.n);
    m.a = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter all elements\n");
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }
    printf("\n\n");
    Display(m);
    return 0;
}