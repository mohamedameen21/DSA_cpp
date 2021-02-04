#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i * i) % SIZE]  != 0)
    {
        i++;
    }
    return (index + i * i) % SIZE;
}

void Insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}

int Search(int H[], int key)
{
    int index = hash(key);

    int i = 0;
    int j = 1;
    while (H[index + i * i % SIZE] != key && j <= SIZE)
    {
        i++;
        j++;
    }
    // if (j > SIZE)
    // {
    //     return -1;
    // }
    return (j > SIZE) ? -1 : (index + i * i) % SIZE;
}

int main()
{

    int HT[SIZE] = {0};

    Insert(HT, 23);
    Insert(HT, 43);
    Insert(HT, 13);
    Insert(HT, 87);
    Insert(HT, 75);

    printf("Key Found at %d \n", Search(HT, 13));

    return 0;
}