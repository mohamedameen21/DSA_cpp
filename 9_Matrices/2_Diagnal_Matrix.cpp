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
        a = new int[n];
    }
    void Set(int i, int j, int x)
    {
        if (i == j)
        {
            a[i - 1] = x;
        }
    }
    int Get(int i, int j)
    {
        if (i == j)
        {
            return a[i - 1];
        }
        else
        {
            return 0;
        }
    }
    void Display()
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {

                    cout << a[i] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout <<endl;
        }
    }
    ~Matrix()
    {
        delete[] a;
    }
};

int main()
{
    Matrix m(4);
    m.Set(1, 1, 5);
    m.Set(2, 2, 8);
    m.Set(3, 3, 9);
    m.Set(4, 4, 12);

    m.Display();
    return 0;
}
