#include <stdio.h>

int fun(int n)
{
    if (n == 0)
    {
        return n;
    }
    return fun(n - 1) + n;
}

//Using formula
int sum(int n)
{
    return n * (n + 1) / 2;
}

//Using loop


int loop(int n)
{
    int sum=0;
    for (size_t i = 0; i <= n; i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    int a = fun(7);
    printf("%d\n", a);
    a = sum(8);
    printf("%d\n", a);
    a=loop(9);
    printf("%d\n", a);

    return 0;
}