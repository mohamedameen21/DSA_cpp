#include <stdio.h>

int main()
{
    char a[] = "WELCOME";
    char b[] = "ameen";
    int i = 0;
    for (; a[i] != '\0'; i++)
    {
        a[i] = a[i] + 32;
    }
    printf("\n%s", a);
    for (; b[i] != '\0'; i++)
    {
        b[i] = b[i] - 32;
    }
    printf("\n%s", b);

    char c[] = "mOHAMED aMEEN";
    for (size_t i = 0; c[i] != '0'; i++)
    {
        if (c[i] >= 65 && c[i] <= 90)
        {
            c[i] = c[i] + 32;
        }
        else if (c[i] >= 97 && c[i] <= 122)
        {
            c[i] = c[i] - 32;
        }
    }
    printf("\n%s", c);

    return 0;
}