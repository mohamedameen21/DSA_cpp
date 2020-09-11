#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        func(n - 1);
        func(n - 1);
    }
}

int main()
{
    int a = 3;
    func(a);
    return 0;
}