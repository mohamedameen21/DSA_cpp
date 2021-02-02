//Iterative is not working
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    int B[100];
    i = l;
    j = mid + 1;
    k = l;

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (j; j <= h; j++)
    {
        B[k++] = A[j];
    }

    for (size_t i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {20, 6, 18, 4, 10, 7, 1}, n = 7;

    MergeSort(A,0,n-1);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}




