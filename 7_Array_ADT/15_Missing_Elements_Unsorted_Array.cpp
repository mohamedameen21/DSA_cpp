#include <stdio.h>
using namespace std;

int main()
{
    int a[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int l = 1, h = 12, n = 10;
    int b[h] = {0};
    for (size_t i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    for (size_t i = l; i < h; i++)
    {
        if (b[i] == 0)
        {
            printf("\nThe missing element is %d",i);
        }
    }

    return 0;
}