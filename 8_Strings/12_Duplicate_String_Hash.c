#include <stdio.h>

int main()
{
    char a[] = "finding";
    char h[26] = {0};
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        h[a[i] - 97]++;
    }
    for (size_t i = 0; i < 25; i++)
    {
        if(h[i]>1)
        {
            printf("\nThe elment %c is occured %d times",i+97,h[i]);
        }
    }
    
    return 0;
}