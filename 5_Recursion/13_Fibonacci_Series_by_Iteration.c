#include <stdio.h>

int fib(int n)
{
    int t1 = 0, t2 = 1, s = 0;
    printf("The fibonacci series are: \n");
    printf("%d %d ", t1, t2);
    for (int i = 2; i <= n; i++)
    {
        s = t1 + t2;
        printf("%d ", s);
        t1 = t2;
        t2 = s;
    }
    return s;
}

int main()
{
    printf("Enter the number of series you want: ");
    int n;
    scanf("%d", &n);
    int sum = fib(n);
    printf("\nSum of the Fibonacci series is: %d ", sum);
    return 0;
}