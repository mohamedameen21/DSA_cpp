#include <stdio.h>

int main()
{
    int a[10] = {3, 6, 8, 8, 12, 15, 15, 15, 20, 20};
    int h[21] = {0};
    //The maximum element is 20 so we want index number till 20 so 21 is the sizee of array

    for (size_t i = 0; i < 10; i++)
    {
        h[a[i]]++;
    }
    for (size_t i = 0; i < 21; i++)
    {
        if (h[i] > 1)
        {
            printf("\nThe element %d is occured %d times ", i, h[i]);
        }
    }
    return 0;
}