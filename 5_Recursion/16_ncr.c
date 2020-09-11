#include <stdio.h>

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

//ncr = n!/r!(n-r)!  formula

int ncr(int n, int r)
{
    int neu = fact(n);
    int dem = fact(r) * fact(n - r);
    return neu/dem;
}

int main()
{
    printf("%d", ncr(4,2));
    return 0;
}