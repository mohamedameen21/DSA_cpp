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
    for(int i=0;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(int i=0;i<arr2->length;i++)
    {
        if(arr2->A[i] != arr3->A[i])
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
        else if(arr1->A[i] == arr2->A[j])
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
        if(arr1->A[i] == arr2->A[i])
        {
            arr3->A[k++] = arr1->A[i];
        }
    }
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array *Set_Difference_Merge(struct Array *arr1, struct Array *arr2 )
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

struct Array *Set_Difference(struct Array *arr1,struct Array *arr2)
{
    int k =0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    for(int i=0;i<arr1->length;i++)
    {
        if(arr1->A[i] != arr2->A[i])
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
    struct Array arr1 = {{3, 7, 18}, 10, 3};
    struct Array arr2 = {{2, 7, 15}, 10, 3};
    struct Array *arr3;
    // arr3 = Set_Union_Merge(&arr1, &arr2);
    // arr3 =  Set_Union(&arr1,&arr2);

    // arr3 = Set_Insertion_Merge(&arr1,&arr2);
    // arr3 = Set_Insertion(&arr1,&arr2);

    // arr3 = Set_Difference(&arr1,&arr2);
    arr3 = Set_Difference(&arr1,&arr2);
    Display(*arr3);
}