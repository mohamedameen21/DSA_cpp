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

void Insert(struct Array *arr, int index, int value) 
//This insert will insert inbetween the array not at
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

void Left_Shift(struct Array *arr, int n)
{
    while (n > 0)
    {
        for (int i = 0; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->A[arr->length - 1] = 0;
        n--;
    }
}

void Right_Shift(struct Array *arr, int n)
{
    while (n > 0)
    {
        for (int i = arr->length - 1; i > 0; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[0] = 0;
        n--;
    }
}

void Left_Roate(struct Array *arr, int n)
{
    while (n > 0)
    {
        int temp;
        temp = arr->A[0];
        for (int i = 0; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->A[(arr->length - 1)] = temp;
        Display(*arr);
        n--;
    }
}

void Right_Roate(struct Array *arr, int n)
{
    while (n > 0)
    {
        int temp;
        temp = arr->A[arr->length - 1];
        for (int i = arr->length - 1; i > 0; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[0] = temp;
        Display(*arr);
        n--;
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
        while (value < arr->A[i] && i >= 0)
        {
            arr->A[i + 1] = arr->A[i];
            i--;
        }
        arr->A[i + 1] = value;
        arr->length++;
    }
}

int Issorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Union_Merge(struct Array *arr1, struct Array *arr2)
//this is o(m+n) = O(n)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Union(struct Array *arr1, struct Array *arr2)
//the oder id O(m*n) = O(n square)
{
    int k;
    k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (int i = 0; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (int i = 0; i < arr2->length; i++)
    {
        if (arr2->A[i] != arr3->A[i])
        {
            arr3->A[k++] = arr2->A[i];
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Insertion_Merge(struct Array *arr1, struct Array *arr2)
//this is o(m+n) = O(n)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Insertion(struct Array *arr1, struct Array *arr2)
//the oder id O(m*n) = O(n square)
{
    int k;
    k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (int i = 0; i < arr1->length; i++)
    {
        if (arr1->A[i] == arr2->A[i])
        {
            arr3->A[k++] = arr1->A[i];
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Difference_Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Difference(struct Array *arr1, struct Array *arr2)
{
    int k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for (int i = 0; i < arr1->length; i++)
    {
        if (arr1->A[i] != arr2->A[i])
        {
            arr3->A[k++] = arr1->A[i];
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
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

    return 0;
}