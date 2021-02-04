#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//In linear probing the key should be less than or equal to half of the hash table
//deletion is not recomeded in lenear probing

int hash(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[index + i] % SIZE != 0)
    {
        i++;
    }
    return (index + i) % SIZE;
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
    while (H[index + i % SIZE] != key && j <= SIZE)
    {
        i++;
        j++;
    }
    // if (j > SIZE)
    // {
    //     return -1;
    // }
    return (j > SIZE) ? -1 : (index + i) % SIZE;
}

int main()
{

    int HT[SIZE] = {0};

    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    Insert(HT, 87);
    Insert(HT, 75); 

    //Inserted element should not be higher than the size of hash 

    printf("Key Found at %d \n", Search(HT, 75));

    return 0;
}
