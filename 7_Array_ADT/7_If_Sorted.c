#include <stdio.h>
#include <stdlib.h>

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

void Sort_and_Insert(struct Array *arr, int value)
{

    if (arr->length == arr->size)
    {
        return; //the function will be stoped 
    }
    else
    {
        int i = arr->length - 1;
        while (value < arr->A[i] && i>=0)
        {
            arr->A[i + 1] = arr->A[i];
            i--;
        }
        arr->A[i+1] = value;
        arr->length++;
    }
}

int Issorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    
}

int main()
{
    struct Array arr = {{1, 2, 25, 7, 9, 23}, 10, 6};
    Display(arr);
    Sort_and_Insert(&arr,8);
    Display(arr);
    printf("\n%d ",Issorted(arr));
}