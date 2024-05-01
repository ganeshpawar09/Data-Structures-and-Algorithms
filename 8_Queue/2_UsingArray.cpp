#include <iostream>
using namespace std;

#define SIZE 100

template <class t>
class queue
{
    t *arr;
    int frontIndex;
    int rearIndex;
    int size;

public:
    queue()
    {
        this->arr = new t[SIZE];
        this->size = size;
        frontIndex = rearIndex = -1;
    }
    queue(int size)
    {
        this->arr = new t[size];
        this->size = size;
        frontIndex = rearIndex = -1;
    }

    bool isEmpty()
    {
        if (frontIndex == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (rearIndex == size - 1)
        {
            return true;
        }
        return false;
    }

    t front()
    {
        if (isEmpty())
        {
            return t();
        }
        return arr[frontIndex];
    }
    void push(t x)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
        }
        else if (isEmpty())
        {
            frontIndex = rearIndex = 0;
        }
        else
        {
            rearIndex++;
        }
        arr[rearIndex] = x;
    }
    t pop()
    {
        if (isEmpty())
        {
            return t();
        }

        t elementToBeDeleted = arr[frontIndex];
        arr[frontIndex] = -1;
        if (frontIndex == rearIndex)
        {
            frontIndex = rearIndex = -1;
        }
        else
        {

            frontIndex++;
        }
        return elementToBeDeleted;
    }
};

int main()
{
    queue<int> a(10);
    a.push(10);
    a.push(100);
    cout << a.front() << endl;
    a.pop();
    cout << a.front() << endl;
    a.pop();
    cout << a.front() << endl;

    return 0;
}