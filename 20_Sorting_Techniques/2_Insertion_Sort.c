//Insertion sort is more useful in Linked list

//Insertion sort by nature it is adaptive

//Insertion sort is also stable (duplicte element)

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insertion(int A[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {11, 12, 7, 2, 6, 9, 4, 5, 10, 3}, n = 10, i;

    Insertion(A,n);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}