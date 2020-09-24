#include <stdio.h>

int n = 0;

void perm(char s[], int k)
{
    static int a[4] = {0};
    static char res[4];
    int i;

    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("\n%s", res);
        n++;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                perm(s, k + 1);
                a[i] = 0;
            }
        }
    }
}

int main()
{
    char s[] = "ABC";
    perm(s, 0);
    printf("\n%d", n);
    return 0;
}