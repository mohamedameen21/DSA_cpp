#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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

void Append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = value;
        //Similar to arr->A[arr->lenthe] = x;
        //arr->length++;
    }
}

void Insert(struct Array *arr, int index, int value) //This insert will insert inbetween the array not at
//the end of the array use append for insertion at the end
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Lenear_Search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

int Lenear_Search_Transpotation(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

int Lenear_Search_Move_Head(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int LBinary_Search(struct Array arr, int key)
{
    int l =0, h= arr.length-1, mid;

    while (l<=h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
        {
            return mid;
        }
        else if(key<arr.A[mid])
        {
            h = mid -1;
        }
        else
        {
            l = mid+1;
        }
        
    }
    return -1;
}

int RBinary_Search(struct Array arr, int key, int l, int h)
{
    int mid=0;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(arr.A[mid]==key)
        {
            return mid;
        }
        else if(key<arr.A[mid])
        {
            RBinary_Search(arr,key,l,mid-1);
        }
        else
        {
            RBinary_Search(arr,key,mid+1,h);
        }
        
    }

    return -1;

}

int main()
{
    struct Array arr;
reenter:
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);
    arr.size = n;
    arr.A = (int *)malloc(n * sizeof(int));
    printf("Enter the number of integers you want to store in an array: ");
    int number_of_int;
    scanf("%d", &number_of_int);
    if (number_of_int > n)
    {
        printf("The number of elements is larger than the size of the array\n");
        goto reenter;
    }
    arr.length = 0;
    printf("Enter the elements one by one: \n");
    for (int i = 0; i < number_of_int; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = number_of_int;

    // Display(arr);
    // Append(&arr, 100);
    // Display(arr);

    // Insert(&arr, 1, 50);
    // Display(arr);

    // Delete(&arr, 0);
    // Display(arr);

    // printf("%d \n", Lenear_Search_Move_Head(&arr, 5));
    // printf("%d \n", Lenear_Search_Move_Head(&arr, 5));
    // printf("%d \n", Lenear_Search_Transpotation(&arr, 5));

    Display(arr);

    printf("\n This is Binary array dont forget to give the as ascending \n ");

    printf("\n%d ",LBinary_Search(arr,5));
    // printf("%d ", RBinary_Search(arr,42,0,arr.length-1));
    return 0;
}