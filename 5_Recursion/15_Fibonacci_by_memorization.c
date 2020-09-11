#include <stdio.h>
#include <stdlib.h>

int f[10] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//it is if we use vector in C++

int fib(int n)
{

    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n-2]==-1 )
        {
            f[n-2] = fib(n-2);
        }
        if (f[n-1]==-1)
        {
            f[n-1] = fib(n-1);
        }
        return fib(n-2)+fib(n-1);
    }
    
}

int main()
{
    int a  = fib(5);
    printf("%d ",a);
    return 0;
}