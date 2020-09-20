#include <stdio.h>

int main()
{
    int arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int key = 10;
    int h[17] = {0};
    for (size_t i = 0; i < 10; i++)
    {
        if (h[key - arr[i]] != 0 && key >= arr[i])
        {
            printf("\n%d + %d = %d", arr[i], key - arr[i], key);
        }
        h[arr[i]]++;
    }

    return 0;
}