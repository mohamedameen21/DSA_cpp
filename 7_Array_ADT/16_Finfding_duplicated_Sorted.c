#include <stdio.h>

int main()
{
    int a[10] = {3,6,8,8,12,15,15,15,20,20};
    int duplicate =0;
    for (size_t i = 0; i < 10; i++)
    {
        if(a[i] == a[i+1] && duplicate != a[i])
        {
            printf("\nThe dupliate element is %d ",a[i]);
            duplicate = a[i];
        }
    }
    
    return 0;
}