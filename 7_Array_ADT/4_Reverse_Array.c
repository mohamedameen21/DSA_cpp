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
    int l = 0, h = arr.length - 1, mid;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int RBinary_Search(struct Array arr, int key, int l, int h)
{
    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            RBinary_Search(arr, key, l, mid - 1);
        }
        else
        {
            RBinary_Search(arr, key, mid + 1, h);
        }
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

int Set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
    return -1;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int LSum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int RSum(struct Array arr, int n)
{
    int sum = 0;
    if (n < 0)
    {
        return 0;
    }
    sum = n + RSum(arr, n - 1);
    return sum;
}

float Avg(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return (float)sum / arr.length;
}

void Ameen_Temp_Reverse1(struct Array *arr)
{
    struct Array rarr;
    rarr.A = (int *)malloc(arr->length * sizeof(int));
    rarr.length = arr->length;
    rarr.size = arr->size;
    for (int i = 0; i < arr->length; i++)
    {
        rarr.A[i] = arr->A[(arr->length - 1) - i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = rarr.A[i];
    }
}

void Ameen_Reverse(struct Array *arr)
{
    int temp;
    for (int i = 0; i < arr->length / 2; i++)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[(arr->length - 1) - i];
        arr->A[(arr->length - 1) - i] = temp;
    }
}

void Temp_Reverse(struct Array *arr)
{
    int *b;
    int i, j;
    b = (int *)malloc(arr->length * sizeof(int));
    for (j = 0, i = arr->length - 1; i >= 0; j++, i--)
    {
        b[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = b[i];
    }
}

void Reverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
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

    // printf("\n This is Binary array dont forget to give the as ascending \n ");

    // printf("\n%d ", LBinary_Search(arr, 5));
    // printf("%d ", RBinary_Search(arr,42,0,arr.length-1));

    // printf("\n%d ",Get(arr,2));
    // Set(&arr,2,37);
    // Display(arr);

    // printf("\n%d ",Max(arr));
    // printf("\n%d ",Min(arr));

    // printf("\n%d ", LSum(arr));
    // printf("\n%d ", RSum(arr, arr.length));
    // printf("\n%f ", Avg(arr));


    Ameen_Reverse(&arr);
    Display(arr);
    Ameen_Temp_Reverse1(&arr);
    Display(arr);
    Temp_Reverse(&arr);
    Display(arr);
    Reverse(&arr);
    Display(arr);

    return 0;
}