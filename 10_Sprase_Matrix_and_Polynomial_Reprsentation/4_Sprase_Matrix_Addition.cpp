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

    friend istream &operator>>(istream &is, Sprase &s);
    friend ostream &operator<<(ostream &os, Sprase &s);
    Sprase operator+(Sprase &s);
};

Sprase Sprase ::operator+(Sprase &s)
{
    int i, j, k;
    if (m != s.m || n != s.n)
    {
        return Sprase(0, 0, 0);
    }
    Sprase *sum = new Sprase(m, n, num + s.num);
    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (e[i].i < s.e[j].i)
        {
            sum->e[k++] = e[i++];
        }
        else if (e[i].i > s.e[j].i)
        {
            sum->e[k++] = s.e[j++];
        }
        else
        {
            if (e[i].j < s.e[j].j)
            {
                sum->e[k++] = e[i++];
            }
            else if (e[i].i > s.e[j].i)
            {
                sum->e[k++] = s.e[j++];
            }
            else
            {
                sum->e[k] = e[i];
                sum->e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }
    for (; i < num; i++)
    {
        sum->e[k++] = e[i];
    }
    for (; j < s.num; j++)
    {
        sum->e[k++] = e[j];
    }
    return *sum;
}

istream &operator>>(istream &is, Sprase &s)
{
    cout << "Enter non zero elements: ";
    for (size_t i = 0; i < s.num; i++)
    {
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}
ostream &operator<<(ostream &os, Sprase &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.e[k].i == i && s.e[k].j == j)
            {
                os << s.e[k++].x << " ";
            }
            else
            {
                os << "0 ";
            }
        }
        os << endl;
    }
    return os;
}

int main()
{
    Sprase s1(5, 5, 5);
    Sprase s2(6, 5, 5);
    cin >> s1;
    cin >> s2;
    cout << "First Matrix " << s1 << endl; 
    cout << "Second Matrix " << s2 << endl;
    Sprase sum = s1 + s2;
    cout << "Sum Matrix " << sum << endl;
    return 0;
}