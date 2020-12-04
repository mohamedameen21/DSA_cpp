#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(NULL)
    {
    }

    void push(int x);
    int pop();
    void display();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stacktop();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Node *t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Stack::display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::peek(int index)
{
    Node *p = top;
    int i;
    for (i = 0; i < index - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p)
    {
        return p->data;
    }
    return -1;
}

int Stack::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::isFull()
{
    Node *t = new Node;
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::stacktop()
{
    if(top!=NULL)
    {
        return top->data;
    }
    return -1;
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();
    cout << st.pop();

    return 0;
}