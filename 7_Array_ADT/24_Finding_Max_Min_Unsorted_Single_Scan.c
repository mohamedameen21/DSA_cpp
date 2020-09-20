#include <stdio.h>

int main()
{
    int a[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int max, min;
    min = a[0];
    max = a[0];
    for (size_t i = 1; i < 10; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("\nThe minimum element in the array is %d", min);
    printf("\nThe maximum element in the array is %d", max);

    return 0;
}