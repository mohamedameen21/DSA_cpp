#include <stdio.h>

int main()
{
    int arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int key = 10;
    for (size_t i = 0; i < 10 - 1; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] + arr[j] == key)
            {
                printf("\n%d + %d = %d",arr[i],arr[j],key);
            }
            
        }
    }

    return 0;
}