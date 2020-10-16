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
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
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

struct Sprase *Add(struct Sprase *s1, struct Sprase *s2)
{
    struct Sprase *sum;
    int i = 0, j = 0, k = 0;
    if(s1->n!=s2->n || s1->m!=s2->m)
    {
        return NULL;
    }
    sum = (struct Sprase *)malloc(sizeof(struct Sprase));
    sum->e = (struct Element *)malloc((s1->num_of_elements + s2->num_of_elements) * sizeof(struct Element));

    while (i < s1->num_of_elements && j < s2->num_of_elements)
    {
        if (s1->e[i].i < s2->e[j].i)
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++] = s2->e[i++];
        }
        else
        {
            if (s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k] = s1->e[i];
                //We can directly copy the struct data members by using =
                //instead of copying the data members one by one
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num_of_elements; i++)
    {
        sum->e[k++] = s1->e[i];
    }
    for (; j < s1->num_of_elements; j++)
    {
        sum->e[k++] = s1->e[j];
    }
    sum->m = s1->m; //== sum->m = s2->m;
    sum->n = s1->n; ////== sum->n = s2->n;
    sum->num_of_elements = k;
    return sum ;
}

int main()
{
    struct Sprase s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3 = Add(&s1,&s2);
    printf("First Matrix \n");
    display(s1);
    printf("Second  Matrix \n");
    display(s2);
    printf("Sum  Matrix \n");
    display(*s3);

    return 0;
}