#include <stdio.h>

int * func(int a[])
{
    return a;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int *p = func(arr);
    printf("%d",*++p);
    return 0;
}