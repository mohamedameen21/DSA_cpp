#include <stdio.h>

double fun(double x, double n)
{
    double s = 1;

    for (; n > 0; n--)
    {
        s = 1 + x / n * s;
    }
    return s;
}

double rec_fun(double x, double n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    s = 1 + x / n * s;
    return rec_fun(x, n - 1);
}

int main()
{
    printf("%lf \n", fun(1, 10));
    printf("%lf \n", rec_fun(1, 10));

    return 0;
}