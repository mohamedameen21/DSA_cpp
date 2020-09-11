#include <stdio.h>

int toh(int n, int a, int b, int c)
{
    static int step = 0;
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        printf("Step no:%d (%d,%d)\n", ++step, a, c);
        toh(n - 1, b, a, c);
    }
}

int main()
{
    toh(3, 1, 2, 3);
    return 0;
}

//Tower of honoi formula  n= 2(power n+1) -1