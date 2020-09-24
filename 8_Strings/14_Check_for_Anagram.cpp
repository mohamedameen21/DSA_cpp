#include <stdio.h>
#include <string.h>
//The letters used in first string is also used in a second string with
//different word without duplicates in any one string then it is said to be Anagram

int main()
{
    char a[] = "decimal";
    char b[] = "medical";
    int i = 0;
    bool flag;
    if (strlen(a) == strlen(b))
    {
        while (a[i] != '\0')
        {
            flag = 0;
            for (int j = 0; b[j] != '\0'; j++)
            {
                if (a[i] == b[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                i++;
            }
            else
            {
                printf("The given strings are not angram\n");
                break;
            }
        }
    }
    else
    {
        printf("The given strings are not angram\n");
    }

    if (a[i] == '\0')
    {
        printf("The given strings are anagram\n");
    }

    return 0;
}