#include <stdio.h>

int main()
{
    char a[] = "azeeza";
    char b[6];
    int i, j;
    for (j = 0; a[j] != '\0'; j++)
    {
    }
    j--;
    for (i = 0; j >= 0; i++, j--)
    {
        b[i] = a[j];
    }
    b[i] = '\0';

    for (int i = 0; a[i] != '\0'; i++)
    //since we have just copied the string so we can use
    //any one condition for for loop
    //Istead for(i=0;a[i]!='\0'&&b[i] != '\0';i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
    }
    if (a[i] == b[i])
    {
        printf("The given string is palindrome\n");
    }
    else
    {
        printf("The given string is not a palindrome\n");
    }

    return 0;
}