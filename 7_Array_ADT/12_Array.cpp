#include <iostream>

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int size)
    // :length(0), size(size)
    {
        this->size = size;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
        std::cout<<"The memory is deleted"<<std::endl;
    }

    void Display()
    {
        printf("\nThe array elements are: \n");
        for (int i = 0; i < length; i++)
        {
            printf("%d ", A[i]);
        }
    }

    void Append(int value)
    {
        if (length < size)
        {
            A[length++] = value;
            //Similar to arr->A[arr->lenthe] = x;
            //arr->length++;
        }
    }

    void Insert(int index, int value)
    //This insert will insert inbetween the array not at
    //the end of the array use append for insertion at the end
    {
        if (index >= 0 && index < length)
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = value;
            length++;
        }
    }

    void Delete(int index)
    {
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            length--;
        }
    }

    int Lenear_Search(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                return i;
            }
        }
        return -1;
    }

    int Lenear_Search_Transpotation(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(&A[i], &A[i - 1]);
                return i;
            }
        }
        return -1;
    }

    int Lenear_Search_Move_Head(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(&A[i], &A[0]);
                return i;
            }
        }
        return -1;
    }

    int LBinary_Search(int key)
    {
        int l = 0, h = length - 1, mid;

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid])
            {
                return mid;
            }
            else if (key < A[mid])
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

    int RBinary_Search(int key, int l, int h)
    {
        int mid = 0;
        if (l <= h)
        {
            mid = (l + h) / 2;
            if (A[mid] == key)
            {
                return mid;
            }
            else if (key < A[mid])
            {
                RBinary_Search(key, l, mid - 1);
            }
            else
            {
                RBinary_Search(key, mid + 1, h);
            }
        }

        return -1;
    }

    int Get(int index)
    {
        if (index >= 0 && index < length)
        {
            return A[index];
        }
        return -1;
    }

    int Set(int index, int value)
    {
        if (index >= 0 && index < length)
        {
            A[index] = value;
        }
        return -1;
    }

    int Max()
    {
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        return max;
    }

    int Min()
    {
        int min = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
            }
        }
        return min;
    }

    int LSum()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum;
    }

    int RSum(int n)
    {
        int sum = 0;
        if (n < 0)
        {
            return 0;
        }
        sum = n + RSum(n - 1);
        return sum;
    }

    float Avg()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return (float)sum / length;
    }

    void Ameen_Temp_Reverse1()
    {
        struct Array rarr;
        rarr.A = (int *)malloc(length * sizeof(int));
        rarr.length = length;
        rarr.size = size;
        for (int i = 0; i < length; i++)
        {
            rarr.A[i] = A[(length - 1) - i];
        }
        for (int i = 0; i < length; i++)
        {
            A[i] = rarr.A[i];
        }
    }

    void Ameen_Reverse()
    {
        int temp;
        for (int i = 0; i < length / 2; i++)
        {
            int temp = A[i];
            A[i] = A[(length - 1) - i];
            A[(length - 1) - i] = temp;
        }
    }

    void Temp_Reverse()
    {
        int *b;
        int i, j;
        b = new int[length];
        for (j = 0, i = length - 1; i >= 0; j++, i--)
        {
            b[j] = A[i];
        }
        for (int i = 0; i < length; i++)
        {
            A[i] = b[i];
        }
    }

    void Reverse()
    {
        int i, j;
        for (i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(&A[i], &A[j]);
        }
    }

    void Left_Shift(int n)
    {
        while (n > 0)
        {
            for (int i = 0; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            A[length - 1] = 0;
            n--;
        }
    }

    void Right_Shift(int n)
    {
        while (n > 0)
        {
            for (int i = length - 1; i > 0; i--)
            {
                A[i] = A[i - 1];
            }
            A[0] = 0;
            n--;
        }
    }

    void Left_Roate(int n)
    {
        while (n > 0)
        {
            int temp;
            temp = A[0];
            for (int i = 0; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            A[(length - 1)] = temp;
            Display();
            n--;
        }
    }

    void Right_Roate(int n)
    {
        while (n > 0)
        {
            int temp;
            temp = A[length - 1];
            for (int i = length - 1; i > 0; i--)
            {
                A[i] = A[i - 1];
            }
            A[0] = temp;
            Display();
            n--;
        }
    }

    void Sort_and_Insert(int value)
    {

        if (length == size)
        {
            return; //the function will be stoped
        }
        else
        {
            int i = length - 1;
            while (value < A[i] && i >= 0)
            {
                A[i + 1] = A[i];
                i--;
            }
            A[i + 1] = value;
            length++;
        }
    }

    int Issorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return 0;
            }
        }
        return 1;
    }

    Array *Merge(Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
            {
                arr3->A[k++] = A[i++];
            }
            else
            {
                arr3->A[k++] = arr2.A[j++];
            }
        }
        for (; i < length; i++)
        {
            arr3->A[k++] = A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr3->A[k++] = arr2.A[j];
        }
        arr3->length = length + arr2.length;
        arr3->size = 10;
        return arr3;
    }

    Array *Set_Union_Merge(Array arr2)
    //this is o(m+n) = O(n)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(length + arr2.length);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
            {
                arr3->A[k++] = A[i++];
            }
            else if (A[i] > arr2.A[j])
            {
                arr3->A[k++] = arr2.A[j++];
            }
            else
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }
        for (; i < length; i++)
        {
            arr3->A[k++] = A[i];
        }
        for (; j < arr2.length; j++)
        {
            arr3->A[k++] = arr2.A[j];
        }
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }

    Array *Set_Union(Array arr2)
    //the oder id O(m*n) = O(n square)
    {
        int k;
        k = 0;
        Array *arr3 = new Array(length + arr2.length);
        for (int i = 0; i < length; i++)
        {
            arr3->A[k++] = A[i];
        }
        for (int i = 0; i < arr2.length; i++)
        {
            if (arr2.A[i] != arr3->A[i])
            {
                arr3->A[k++] = arr2.A[i];
            }
        }
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }

    Array *Set_Insertion_Merge(Array arr2)
    //this is o(m+n) = O(n)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(size);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
            {
                i++;
            }
            else if (A[i] > arr2.A[j])
            {
                j++;
            }
            else if (A[i] == arr2.A[j])
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }

        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }

    Array *Set_Insertion(Array arr2)
    //the oder id O(m*n) = O(n square)
    {
        int k;
        k = 0;
        Array *arr3 = new Array(size);
        for (int i = 0; i < length; i++)
        {
            if (A[i] == arr2.A[i])
            {
                arr3->A[k++] = A[i];
            }
        }

        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }

    Array *Set_Difference_Merge(Array arr2)
    {
        int i, j, k;
        i = j = k = 0;
        Array *arr3 = new Array(size);

        while (i < length && j < arr2.length)
        {
            if (A[i] < arr2.A[j])
            {
                arr3->A[k++] = A[i++];
            }
            else if (A[i] > arr2.A[j])
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        for (; i < length; i++)
        {
            arr3->A[k++] = A[i];
        }

        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }

    Array *Set_Difference(Array arr2)
    {
        int k = 0;
        Array *arr3 = new Array(size);

        for (int i = 0; i < length; i++)
        {
            if (A[i] != arr2.A[i])
            {
                arr3->A[k++] = A[i];
            }
        }
        arr3->length = k;
        arr3->size = 10;
        return arr3;
    }
};

int main()
{
    Array *arr;
    int ch, x, index, value, n;

    std::cout << "Enter the Array size: ";
    std::cin >> n;
    arr = new Array(n);

    do
    {
        printf("\n\nMenu\n\n");
        printf("1.Append\n");
        printf("2.Insert\n");
        printf("3.Display\n");
        printf("4.Search\n");
        printf("5.Get value\n");
        printf("6.Replace\n");
        printf("7.Max value\n");
        printf("8.Minimum value\n");
        printf("9.Sum\n");
        printf("10.Check If the array is sorted\n");
        printf("11.Delete\n");
        printf("12.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the value to Append : ");
            scanf("%d", &value);
            arr->Append(value);
            break;
        case 2:
            printf("\nEnter the index to insert the value : ");
            scanf("%d", &index);
            printf("\nEnter the value to insert : ");
            scanf("%d", &value);
            arr->Insert(index, value);
            break;
        case 3:
            arr->Display();
            break;
        case 4:
            printf("\nEnter the value to search: ");
            scanf("%d", &value);
            x = arr->Lenear_Search(value);
            if (x > 0)
            {
                printf("\nThe value is found at the index %d", x);
            }
            else
            {
                printf("\nThe value is not found\n");
            }
            break;
        case 5:
            printf("\nEnter the index to get value: ");
            scanf("%d", &index);
            x = arr->Get(index);
            printf("\nThe value at the given index is %d ", x);
            break;
        case 6:
            printf("Enter the index value : ");
            scanf("%d", &index);
            printf("Enter the value : ");
            scanf("%d", &value);
            x = arr->Set(index, value);
            if (x == -1)
            {
                printf("\nThe value is not Replaced ");
            }
            break;
        case 7:
            printf("\nThe maximum value of the given array is %d", arr->Max());
            break;
        case 8:
            printf("\nThe minimum value in the given array is %d ", arr->Min());
            break;
        case 9:
            printf("\nThe sum of the array is %d ", arr->LSum());
            break;
        case 10:
            x = arr->Issorted();
            if (x)
            {
                printf("\nThe array is sorted ");
            }
            else
            {
                printf("The array is not sorted");
            }
            break;
        case 11:
            printf("\nEnter the index to delete the value: ");
            scanf("%d", &index);
            arr->Delete(index);
            break;
        default:

            break;
        }
    } while (ch < 12);

    return 0;
}