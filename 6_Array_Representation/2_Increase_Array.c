#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(5 * sizeof(int));
    for (size_t i = 0; i < 5; i++)
    {
        p[i] = i;
    }

    printf("Array elements : \n");

    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }

    //to make array of larger size

    int *q = (int *)malloc(10 * sizeof(int));
    for (size_t i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    printf("\nAfter elements after copying in q : \n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", q[i]);
    }

    free(p);
    p = q;
    q = NULL;

    printf("\n Array elements after extending : \n");

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }

    return 0;
}