#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a[5] = {0};
    int *p;
    p = (int *)malloc(5*sizeof(int));
    for (size_t i = 0; i < 4; i++)
    {
        p[i] = i;
    }
    
    return 0;
}