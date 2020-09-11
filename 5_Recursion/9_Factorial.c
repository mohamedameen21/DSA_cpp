#include <stdio.h>

int rec_fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return rec_fact(n - 1) * n;
}

int loop_fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int fact = 1;
    for (size_t i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int a = rec_fact(5);
    printf("%d\n", a);
    a = loop_fact(5);
    printf("%d\n", a);

    a = rec_fact(0);
    printf("%d\n", a);

    a = loop_fact(0);
    printf("%d\n", a);

    return 0;
}