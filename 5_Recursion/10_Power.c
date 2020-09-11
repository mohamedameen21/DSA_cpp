#include <stdio.h>

// int power(int m, int n)
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     return m*power(m,n-1);
// }

//Below is faster version

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n%2==0)
    {
        return power(m*m,n/2);
    }
    else
    {
        return m*power(m*m,(n-1)/2);
    }
    
    // return m * power(m, n - 1);
}

int main()
{
    int a = power(2,5);
    printf("%d\n",a);
    return 0;
}