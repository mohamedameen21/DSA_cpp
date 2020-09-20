#include <stdio.h>

int main()
{
    int a[10] = {3, 6, 8, 8, 12, 15, 15, 15, 20, 20};
    int j = 0;
    for (size_t i = 0; i < 10 - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            j = i + 1;
            while (a[i] == a[j])
            {
                j++;
            }
            printf("\nThe dupliate element  %d occured %d times", a[i], j - i);
            i = j - 1;
        }
    }

    return 0;
}