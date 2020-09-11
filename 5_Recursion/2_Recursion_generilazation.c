#include <stdio.h>

void func(int n)
{
    if(n>0)
    {
        //The code before the function call is called acesnding 
        //the code written above the function call will execut at functio 
        //compile time or runtime 
        func(n-1);

        //The code after the fuction call is called descending 
        //the code written after the function call will execute at 
        //the function returninig time.......
    }
}

//Recusion vs loop
//in loop only ascending code is there 
//but in recusion there is recusion and ascending and desceinding code 



int main()
{
    return 0;
}