#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sprase
{
private:
    int m;
    int n;
    int num;
    Element *e;

public:
    Sprase(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[this->num];
    }
    ~Sprase()
    {
        delete[] e;
    }
    void read()
    {
        cout << "Enter non zero elements: ";
        for (size_t i = 0; i < num; i++)
        {
            cin >> e[i].i >> e[i].j >> e[i].x;
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (e[k].i == i && e[k].j == j)
                {
                    cout << e[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Sprase s1(5,5,5);
    s1.read();
    s1.display();
    

    return 0;
}