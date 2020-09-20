#include <stdio.h>

int main()
{
    int a[] = {8, 3, 6, 4, 6, 5, 6, 2, 8, 7};
    int h[9] = {0};
    for (size_t i = 0; i < 10; i++)
    {
        h[a[i]]++;
    }
    for (size_t i = 0; i < 9; i++)
    {
        if (h[i] > 1)
        {
            printf("\nThe element %d is occured %d times ", i, h[i]);
        }
    }

    return 0;
}