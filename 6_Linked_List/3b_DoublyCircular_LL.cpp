#include <iostream>
using namespace std;

template <class t>
class Node
{
public:
    t data;
    Node<t> *next;
    Node<t> *prev;
    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
    t getData()
    {
        return data;
    }

    Node<t> *getNext()
    {
        return next;
    }

    Node<t> *getPrev()
    {
        return prev;
    }
    void setData(t x)
    {
        this->data = x;
    }

    void setNext(Node<t> *x)
    {
        this->next = x;
    }

    void setPrev(Node<t> *x)
    {
        this->prev = x;
    }
};
template <class t>
class dcll
{
    Node<t> *tail;

public:
    dcll()
    {
        tail = NULL;
    }
    void insertElement(t x)
    {
        Node<t> *newNode = new Node<t>();
        newNode->setData(x);

        if (tail == NULL)
        {
            newNode->setPrev(newNode);
            newNode->setNext(newNode);
            tail = newNode;
        }
        else
        {
            Node<t> *nextNode = tail->getNext();
            newNode->setPrev(tail);
            newNode->setNext(nextNode);
            nextNode->setPrev(newNode);
            tail->setNext(newNode);

            tail = newNode;
        }
    }
    void printdcll()
    {
        Node<t> *temp = tail;
        cout << "\nTail: " << tail->getData() << endl;
        do
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        } while (temp != tail);
        cout << endl;
    }
    void printdcllR()
    {
        Node<t> *temp = tail;
        cout << "\nTail: " << tail->getData() << endl;
        do
        {
            cout << temp->getData() << " ";
            temp = temp->getPrev();
        } while (temp != tail);
        cout << endl;
    }
};

int main()
{
    dcll<int> a;
    a.insertElement(2);
    a.insertElement(3);
    a.insertElement(4);
    a.printdcll();
    a.printdcllR();
    return 0;
}