#include <stdio.h>

//please refer the video to see the pascal triangle law

int c(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }

    else
    {
        return c(n - 1, r - 1) + c(n - 1, r);
        /* code */
    }
}

int main()
{
    printf("%d ", c(5,3));
    return 0;
}




