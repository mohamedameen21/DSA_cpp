#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h); 
    }
}

int main()
{
    int A[] = {7,6,10,5,9,2,1,15,7, __INT_MAX__}, n = 10, i;

    QuickSort(A,0,n-1);

    for (size_t i = 0; i < n-1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}