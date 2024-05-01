#include <iostream>
using namespace std;

template <class t>
class Node
{
    t data;
    Node<t> *next;

public:
    Node()
    {
        this->next = NULL;
    }

    void setData(t x)
    {
        this->data = x;
    }
    void setNext(Node<t> *x)
    {
        this->next = x;
    }
    t getData()
    {
        return data;
    }
    Node<t> *getNext()
    {
        return next;
    }
};

template <class t>
class cll
{
    Node<t> *tail;

public:
    cll()
    {
        tail = NULL;
    }

    void insertElement(t x)
    {
        Node<t> *newNode = new Node<t>();
        newNode->setData(x);

        if (tail == NULL)
        {
            newNode->setNext(newNode);
            tail = newNode;
        }
        else
        {
            newNode->setNext(tail->getNext());
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    void deleteElement(t x)
    {
        if (tail == NULL)
        {
            cout << "CLL is empty" << endl;
        }
        else if (tail->getNext() == tail)
        {
            delete tail;
            tail = NULL;
        }
        else
        {
            Node<t> *temp = tail;
            while (temp->getNext()->getData() != x)
            {
                temp = temp->getNext();
            }
            Node<t> *nodeToBeDeleted = temp->getNext();
            Node<t> *nextNode = temp->getNext()->getNext();

            if (nodeToBeDeleted == tail)
            {
                tail = nextNode;
            }
            delete nodeToBeDeleted;

            temp->setNext(nextNode);
        }
    }

    void printcll()
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
};

int main()
{
    cll<int> a;
    a.insertElement(2);
    a.insertElement(3);
    a.insertElement(4);
    a.insertElement(5);
    a.insertElement(6);
    a.printcll();

    a.deleteElement(4);
    a.printcll();

    a.deleteElement(6);
    a.printcll();

    cll<string> b;
    b.insertElement("abd");
    b.insertElement("abd");
    b.insertElement("abd");
    b.insertElement("abd");
    b.printcll();

    return 0;
}