#include <stdio.h>

int main()
{
    char a[] = "finding";
    int h = 0;
    int i, x = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x << a[i] - 97;
        if ((x & h) > 0)
        {
            printf("%c is duplicate\n", a[i]);
        }
        else
        {
            h = x | h;
        }
    }
    return 0;
}