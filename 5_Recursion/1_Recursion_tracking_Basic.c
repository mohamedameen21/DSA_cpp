#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        func(n - 1);
    }
}

void func2(int n)
{
    if (n > 0)
    {
        func2(n - 1);
        printf("%d", n);
    }
}

int main()
{
    int x = 3;
    printf("\nThere is first printing and calling the function \n");
    func(x);
    printf("\n But in here calling the function then printing the when the function is returning\n");
    func2(x);
    return 0;
}