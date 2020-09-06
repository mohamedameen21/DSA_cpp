#include <stdio.h>

struct Rectangle
{
    int length;
    int breath;
    int ar[5];
};

void func(struct Rectangle r)
{
    //even array cannot be passed as a call by value 
    //inside structure we can pass 
    r.length = 11;
}

void pfunc(struct Rectangle *r)
{
    r->length = 11;
}

int main()
{
    struct Rectangle r = {10,20,{1,2,3,4,5}};
    func(r);
    printf("%d\n", r.length);

    pfunc(&r);
    printf("%d\n",r.length);
    return 0;
}