#include <stdio.h>

int main()
{
    char a[] = "madam";
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        /* code */
    }
    i--;
    int j;
    for (j = 0; j < i; i--, j++)
    {
        if (a[j] != a[i])
        {
            printf("The given string is not a palindrome\n");
            break;
        }
    }
    if (a[i] == a[j])
    {
        printf("The given string is palindrome\n");
    }
    return 0;
}