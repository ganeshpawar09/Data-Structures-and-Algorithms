#include <iostream>
using namespace std;

template <class t>
class stack
{
    t *arr;
    int topIndex;
    int allowedSize;

public:
    stack(int size)
    {
        this->arr = new t[size];
        this->topIndex = -1;
        this->allowedSize = size;
    }

    bool isFull()
    {
        if (topIndex == allowedSize - 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (topIndex == -1)
        {
            return true;
        }
        return false;
    }

    void push(t x)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++topIndex] = x;
        }
    }
    t pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            int elementTobeDeleted = arr[topIndex];
            arr[topIndex--] = -1;
        }
    }
    t top()
    {
        if (isEmpty())
        {
            return t();
        }
        else
        {
            return arr[topIndex];
        }
    }
    int size()
    {
        return topIndex + 1;
    }
};

int main()
{
    stack<int> a(3);
    a.pop();
    a.push(2);
    a.push(2);
    a.push(2);
    cout << "Top: " << a.top() << endl;
    cout << "Size: " << a.size() << endl;
    return 0;
}