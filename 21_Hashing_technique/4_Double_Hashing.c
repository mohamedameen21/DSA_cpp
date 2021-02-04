#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define PRIME 7

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return PRIME - (key % PRIME);
}

int probe(int H[], int key)
{
    int index = hash1(key);
    int i = 0;
    while ((H[(hash1(key) + i * hash2(key)) % 10] != 0))
    {
        i++;
    }
    return (hash1(key) + (i * hash2(key))) % 10;
}

void Insert(int H[], int key)
{
    int index = hash1(key);

    if (H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}

int main()
{
    int H[SIZE] = {0};

    Insert(H, 5);
    Insert(H, 25);
    Insert(H, 15);
    Insert(H, 35);
    Insert(H, 95);

    return 0;
}