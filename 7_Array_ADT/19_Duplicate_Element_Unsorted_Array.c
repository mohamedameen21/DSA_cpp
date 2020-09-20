#include <stdio.h>

int main()
{
    int a[] = {8, 3, 6, 4, 6, 5, 6, 2, 8, 7};
    int count = 0;
    for (size_t i = 0; i < 10 - 1; i++)
    {
        count = 1;
        if (a[i] != -1)
        {
            for (size_t j = i + 1; j < 10; j++)
            {
                if (a[i] == a[j])
                {
                    count++;
                    a[j] = -1;
                }
            }
            if(count>1)
            {
                printf("\nThe element %d is %d times ",a[i],count);
            }
        }
    }

    return 0;
}