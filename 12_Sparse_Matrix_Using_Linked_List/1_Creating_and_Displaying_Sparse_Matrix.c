#include <stdio.h>
#include <stdlib.h>

//Really I dont know about how to solve this problem but I will try my best

struct Node
{
    int col;
    int data;
    struct Node *next;
};
int row, col;
struct Node *A[3];

void userinput()
{
    int count = 0;
    printf("Enter the number of rows: \n");
    scanf("%d", &row);
    printf("Enter the number of columns: \n");
    scanf("%d", &col);
    // const int size = row;
    //In c we cant able to specify the variable name in array size so we can try it in c++ afterwards
    printf("Enter the elements one by one: ");
    int ele;
    struct Node *temp, *last, *Head;
    for (size_t i = 0; i < row; i++)
    {
        count = 0;
        int flag = 1;
        for (size_t j = 0; j < col; j++)
        {
            scanf("%d ", &ele);
            if (ele && flag)
            {
                Head = (struct Node *)malloc(sizeof(struct Node));
                Head->data = ele;
                Head->col = j;
                Head->next = NULL;
                A[i] = last = Head;
                flag = 0;
            }
            if (ele && count)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->col = j;
                temp->data = ele;
                temp->next = NULL;
                last->next = temp;
                last = temp;
            }
            if (ele)
            {
                count++;
            }
        }
    }
}

void display()
{
    struct Node *p;
    for (size_t i = 0; i < row; i++)
    {
        p = A[i];
        for (size_t j = 0; j < col; j++)
        {
            if (p)
            {

                if (j == p->col)
                {
                    printf("%d ", p->data);
                    p = p->next;
                }
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
    userinput();
    display();
    return 0;
}