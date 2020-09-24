#include <stdio.h>

int main()
{
    char a[] = "How are        you?";
    int word = 1;
    for (size_t i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 32 && a[i - 1] != 32)
        {
            word++;
        }
    }
    // char b =' ';
    // printf("%d",b);
    printf("\nNumber of words in string is %d", word);

    return 0;
}