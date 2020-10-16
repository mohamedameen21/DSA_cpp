#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sprase
{
    int m;
    int n;
    int num_of_elements;
    struct Element *e;
};

void create(struct Sprase *s)
{
    printf("Enter the number of rows: ");
    scanf("%d", &s->m);
    printf("Enter the number of columns: ");
    scanf("%d", &s->n);
    printf("Enter the number of non zero elements: ");
    scanf("%d", &s->num_of_elements);
    s->e = (struct Element *)malloc(s->num_of_elements * sizeof(struct Element));
    printf("Enter all non zero elements: \n");
    for (size_t i = 0; i < s->num_of_elements; i++)
    {
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct Sprase s)
{
    int i, j, k = 0;
    for (i = 0; i < s.num_of_elements; i++)
    {
        for (j = 0; j < s.num_of_elements; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                printf("%d ", s.e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Sprase s; 
    create(&s);
    display(s);

    return 0;
}