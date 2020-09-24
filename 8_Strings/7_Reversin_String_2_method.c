#include <stdio.h>

int main()
{
    int i, j;
    int temp;
    char a[] = "python";
    // char b[7];
    //To find the length of the string

    for (j = 0; a[j] != '\0'; j++)
    {
    }
    j--; //to poin t the j to last character in string

    // for (i = 0; i < j; i++, j--)
    // {
    //     temp = a[i];
    //     a[i] = a[j];
    //     a[j] = temp;
    // }


    //Below is my method
    for (i = 0; i < j / 2; i++)
    {
        temp = a[i];
        a[i] = a[j - i];
        a[j - i] = temp;
    }

    printf("\n%s ", a);

    return 0;
}