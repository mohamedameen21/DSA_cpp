#include <iostream>
using namespace std;

class Matrix
{
private:
    int *a;
    int n;

public:
    Matrix(int n)
    {
        this->n = n;
        a = new int[n * (n - 1) / 2];
    }
    void Set(int i, int j, int x)
    {
        if (i >= j)
        {
            a[n*(j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
        }
    }
    int Get(int i, int j)
    {
        if (i >= j)
        {
            return a[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
        }
        else
        {
            return 0;
        }
    }
    void Display()
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                {

                    cout << a[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    int Getdimension() { return n; }
    ~Matrix()
    {
        delete[] a;
    }
};

int main()
{
    int d;
    printf("Enter the dimension: ");
    cin >> d;

    Matrix m(d);
    int x, i, j;
    printf("Enter all elements : \n");
    for (i = 1; i <= d; i++)
    {
        for (j = 1; j <= d; j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }
    cout << endl
         << endl;
    m.Display();
    return 0;
}
