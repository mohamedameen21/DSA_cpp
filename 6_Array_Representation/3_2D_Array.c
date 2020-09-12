#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Creating the 2D array in stack
    int a[3][4] = {0};

    //Creating the 2D array half in stack and half in heap
    int *b[3];
    b[0] = (int *)malloc(4 * sizeof(int));
    b[1] = (int *)malloc(4 * sizeof(int));
    b[2] = (int *)malloc(4 * sizeof(int));

    //Creating the 2D array in heap 
    int **c;
    c = (int **) malloc(3*sizeof(int));
    c[0] = (int *)malloc(4 * sizeof(int));
    c[1] = (int *)malloc(4 * sizeof(int));
    c[2] = (int *)malloc(4 * sizeof(int));

    return 0;
}