#include <stdio.h>

int main()
{
    int a[] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 12};
    int k = 10;
    int i = 0;
    int j = 10 - 1;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            printf("\n%d + %d = %d", a[i], a[j], k);
            i++;
            j--;
        }
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return 0;
}