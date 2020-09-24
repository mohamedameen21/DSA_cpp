#include <stdio.h>

int main()
{
    // char a[] = "decimal";
    // char b[] = "medical";

    //Strings with duplicates
    char a[] = "verbose";
    char b[] = "observe";

    int i, h[26] = {0};
    for (i = 0; a[i] != '\0'; i++)
    {
        h[a[i] - 97]++;
    }
    for (i = 0; b[i] != '\0'; i++)
    {
        h[b[i] - 97] -= 1;
        if (h[b[i] - 97] < 0)
        {
            printf("The given string are not anagram\n");
            break;
        }
    }

    if (b[i] == '\0')
    {
        printf("The given string are anagram\n");
    }

    return 0;
}