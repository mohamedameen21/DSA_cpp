#include <stdio.h>

int main()
{
    char a[] = "findinig";
    int len = 8;
    // int last_index = len-1;
    int i, j, count;
    for (i = 0; i < len - 1; i++)
    {
        count = 1;
        for (j = i + 1; j < len; j++)
        {
            if (a[i] == ' ')
            {
                continue;
            }
            if (a[i] == a[j])
            {
                count++;
                a[j] = ' ';
            }
        }
        if (count > 1)
        {
            printf("\nThe element %c id occur %d times", a[i], count);
        }
    }
    return 0;
}