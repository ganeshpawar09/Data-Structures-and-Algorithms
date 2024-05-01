#include <iostream>
using namespace std;

template <class t>
class stack;

template <class t>
class Node
{
    t data;
    Node<t> *next;

public:
    friend class stack<t>;

    Node(t data)
    {
        this->data = data;
        next = NULL;
    }
};

template <class t>
class stack
{
    Node<t> *topPointer;

public:
    stack()
    {
        topPointer = NULL;
    }
    bool isEmpty()
    {
        if (topPointer == NULL)
        {
            return true;
        }
        return false;
    }
    void push(t data)
    {
        Node<t> *newnode = new Node<t>(data);
        newnode->next = topPointer;
        topPointer = newnode;
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
        {
            topPointer = topPointer->next;
        }
    }
    t top()
    {
        if (isEmpty())
            return t();
        else
            return (topPointer->data);
    }
};

int main()
{
    stack<int> s1, s2;
    s1.push(23);
    s1.push(24);
    s1.push(25);
    s1.push(26);
    s1.push(27);
    cout << s1.top() << endl;

    return 0;
}