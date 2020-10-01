//using lower triangular matrix

//2 2 2 2 2
//2 3 3 3 3
//2 3 4 4 4
//2 3 4 5 5
//2 3 4 5 6

//This matrix can be reprsented either lower triangular or upper triangular

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
        m->a[i * (i - 1) / 2 + j - 1] = element;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.a[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return Get(m,j,i);
    }
}

void Display(struct Matrix m)
{
    int i, j, x;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                x = m.a[i * (i - 1) / 2 + j - 1];
                printf("%d ", m.a[i * (i - 1) / 2 + j - 1]);
            }
            else
            {
                printf("%d ",x);
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i, j;
    int x;
    printf("Enter the dimension: ");
    scanf("%d", &m.n);
    m.a = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    // for (int i = 0; i < m.n; i++)
    // {
    //     m.a[0] = 0;
    // }

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

    printf("\n%d\n",Get(m,3,4));
    printf("\n%d\n",Get(m,2,5));
    return 0;
}