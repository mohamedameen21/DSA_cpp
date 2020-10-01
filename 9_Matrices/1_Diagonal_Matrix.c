#include <stdio.h>

struct Matrix
{
    int a[10];
    int n;
};

void Set(struct Matrix *m, int i, int j, int element)
{
    if (i == j)
    {
        m->a[i - 1] = element;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
    {
        return m.a[i - 1];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
            {
                printf("%d ", m.a[i]);
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
    m.n = 4;

    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);

    printf("%d \n", Get(m, 2, 2));

    Display(m);

    return 0;
}