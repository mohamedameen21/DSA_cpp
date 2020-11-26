#include <iostream>
#define Row 5
using namespace std;



//Really I dont know about how to solve this problem but I will try my best

struct Node
{
    int col;
    int data;
    struct Node *next;
};
int row, col;
struct Node *A[Row];

void userinput()
{
    int count = 0;
    cout<<"Enter the number of rows: \n";
    cin>>row;
    cout<<"Enter the number of columns: \n";
    cin>>col;
    // const int size = row;
    //In c we cant able to specify the variable name in array size so we can try it in c++ afterwards
    cout<<"Enter the elements one by one: ";
    int ele;
    struct Node *temp, *last, *Head;
    for (size_t i = 0; i < row; i++)
    {
        count = 0;
        int flag = 1;
        for (size_t j = 0; j < col; j++)
        {
            cin>>ele;
            if (ele && flag)
            {
                Head = new  Node;
                Head->data = ele;
                Head->col = j;
                Head->next = NULL;
                A[i] = last = Head;
                flag = 0;
            }
            if (ele && count)
            {
                temp = new Node;
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
                    cout<<p->data<<" ";
                    p = p->next;
                }
                else
                {
                    cout<<"0 ";
                }
                
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    userinput();
    cout<<"Displaying Sparse Matrix "<<endl;
    display();
    return 0;
}