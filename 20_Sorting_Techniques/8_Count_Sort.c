#include <stdio.h>
#include <stdlib.h>

int findmax(int A[], int n)
{
    int max = A[0], i = 0;
    while (i < n)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        i++;
    }
    return max;
}

void CountSort(int A[], int n)
{
    int max = findmax(A, n);
    int *C = (int *)malloc((max + 1) * sizeof(int));
    for (size_t i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3}, n = 10;
    
    CountSort(A,n);
    printf("Hello\n");

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}