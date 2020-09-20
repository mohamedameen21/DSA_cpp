#include <iostream>
using namespace std;

template <class T>
class Array
{
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[size];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
        cout<<"The Dynamic Array is deleted"<<endl;
    }
    void display();
    void insert(int index, T value);
    T Delete(int index);
};

template <class T>
// template <class T1> here we can chahge the template name because no template type is
// void Array<T1>::display()  used int this function
void Array<T>::display()
{
    for (size_t i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
// template <class T1>   //But here we cannot change it because here we used a 
// void Array<T1>::insert(int index, T value)  template datetype in tis function
void Array<T>::insert(int index, T value)
{
    if (length == size)
    {
        return;
    }

    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i] = A[i + 1];
        }
        A[index] = value;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        T x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
}

int main()
{
    Array<char> arr(10);
    arr.insert(0, 'a');
    arr.insert(1, 'b');
    arr.insert(2, 'c');
    arr.display();
    cout << arr.Delete(0) << endl;
    arr.display();
    return 0;
}