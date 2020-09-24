#include <stdio.h>

int main()
{
    char a[] = "How are you?";
    int vcount = 0, ccount = 0;
    for (size_t i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'A' || a[i] == 'e' || a[i] == 'E' || a[i] == 'i' || a[i] == 'I' || a[i] == 'o' || a[i] == 'O' || a[i] == 'u' || a[i] == 'U')
        {
            vcount++;
        }
        else if (a[i] >= 65 && a[i] <= 90 || a[i] >= 97 && a[i] <= 122)
        {
            ccount++;
        }
    }
    printf("\nNumber of vowels are %d ", vcount);
    printf("\nNumber of consonents are %d ",ccount);
    return 0;
}