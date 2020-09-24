#include <stdio.h>

int main()
{
    char a[] = "painter";
    char b[] = "Painter";
    int i, j;

    for (int i = 0; a[i] != '\0'; i++)
    { 
        if (a[i] >= 65 && a[i] <= 90)
        {
            a[i] = a[i] + 32;
        }
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] >= 65 && b[i] <= 90)
        {
            b[i] = b[i] + 32;
        }
    }

    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
    {
        printf("Both the strings are equal\n");
    }
    else if (a[i] < b[j])
    {
        printf("1st String is smaller\n");
    }
    else
    {
        printf("1st String is bigger\n");
    }

    //The output will be differ depending upon the capital letter or smaller letter so first
    //convert them to either capital or small
}