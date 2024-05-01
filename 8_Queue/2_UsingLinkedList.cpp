#include <iostream>
using namespace std;

template <class t>
class queue;

template <class t>
class Node
{
    t data;
    Node *next;

public:
    friend class queue<t>;
    Node(t data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class t>
class queue
{
    Node<t> *frontPointer;
    Node<t> *rearPointer;

public:
    queue()
    {
        this->frontPointer = NULL;
        this->rearPointer = NULL;
    }

    bool isEmpty()
    {
        if (frontPointer == NULL)
        {
            return true;
        }
        return false;
    }

    void push(int x)
    {
        Node<t> *newNode = new Node<t>(x);

        if (frontPointer == NULL)
        {
            frontPointer = rearPointer = newNode;
        }
        else
        {
            rearPointer->next = newNode;
            rearPointer = newNode;
        }
    }
    t pop()
    {
        if (frontPointer == NULL)
        {
            return t();
        }

        t elementToBeDeleted = frontPointer->data;
        if (frontPointer == rearPointer)
        {
            delete frontPointer;
            frontPointer = rearPointer = NULL;
        }
        else
        {
            Node<t> *temp = frontPointer;
            frontPointer = frontPointer->next;
            delete temp;
        }
        return elementToBeDeleted;
    }
    t front()
    {
        if (frontPointer == NULL)
        {
            return t();
        }
        return frontPointer->data;
    }
};

int main()
{
    queue<int> a;
    cout << a.front() << endl;
    a.push(10);
    cout << a.front() << endl;
    cout << a.pop() << endl;
    cout << a.front() << endl;
    cout << a.pop() << endl;
    ;
    return 0;
}