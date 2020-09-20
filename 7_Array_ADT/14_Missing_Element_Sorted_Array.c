#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nThe array elements are: \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

//Fisrt n natural numbers
int Find_Missing_Sorted_First_Natural(struct Array arr, int n)
{
    int sum = 0, s;
    for (size_t i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    s = n * (n + 1) / 2;
    return s - sum;
}

int Find_Missing_Sorted_Random_Natural(struct Array arr, int first, int last, int n)
{
    int diff = first - 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr.A[i] - i != diff)
        {
            // printf("The Missing Element is found %d",i+diff);
            // break;

            return i + diff;
        }
    }
}

void Find_More_Missing_Sorted_Random_Natural(int A[], int first, int last, int n)
{
    int diff = first - 0;
    for (size_t i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                printf("\nThe missing element is %d", diff + i);
                diff++;
            }
        }
    }
}

int main()
{
    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11}, 10, 10};
    struct Array arr2 = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16}, 10, 10};
    printf("The Missing Elements is %d\n", Find_Missing_Sorted_First_Natural(arr1, 11));
    printf("The Missing Element is %d", Find_Missing_Sorted_Random_Natural(arr2, 6, 16, 10));
    int a[] = {6, 7, 8, 9, 11, 12, 15, 16, 17};
    Find_More_Missing_Sorted_Random_Natural(a, 6, 17, 9);
    return 0;
}