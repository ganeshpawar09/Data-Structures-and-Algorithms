#include <iostream>
using namespace std;

template<class t>
class Node
{
    t data;
    Node<t> *next;
    Node<t> *prev;

public:
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
template<class t>
class dll
{
    Node<t> *head;
    Node<t> *tail;

public:
    dll()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void insertAtHead(t x)
    {
        Node<t> *newNode = new Node<t>();
        newNode->setData(x);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->setPrev(newNode);
            newNode->setNext(head);
            head = newNode;
        }
    }

    void insertAtTail(t x)
    {
        Node<t> *newNode = new Node<t>();
        newNode->setData(x);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            newNode->setPrev(head);
            tail = newNode;
        }
    }

    void insertAfterIt(t x, t afterIt)
    {
        if (head == NULL)
        {
            insertAtHead(x);
        }
        else if (tail->getData() == afterIt)
        {
            insertAtTail(x);
        }
        else
        {
            Node<t> *temp = head;

            while (temp != NULL && temp->getData() != afterIt)
            {
                temp = temp->getNext();
            }
            Node<t> *nextNode = temp->getNext();

            Node<t> *newNode = new Node<t>();
            newNode->setData(x);

            newNode->setPrev(temp);
            newNode->setNext(nextNode);

            temp->setNext(newNode);
            nextNode->setPrev(newNode);
        }
    }

    void deleteElement(t x)
    {
        if (head == NULL)
        {
            cout << "DLL is empty" << endl;
        }
        else if (head->getData() == x)
        {
            Node<t> *nextNode = head->getNext();
            nextNode->setPrev(NULL);
            delete head;
            head = nextNode;
        }
        else if (tail->getData() == x)
        {
            Node<t> *prevNode = tail->getPrev();
            prevNode->setNext(NULL);
            delete tail;
            tail = prevNode;
        }
        else
        {
            Node<t> *temp = head;
            while (temp != NULL && temp->getData() != x)
            {
                temp = temp->getNext();
            }
            if (temp == NULL)
            {
                cout << "Element Not Found" << endl;
            }
            else
            {
                Node<t> *prevNode = temp->getPrev();
                Node<t> *nextNode = temp->getNext();
                prevNode->setNext(nextNode);
                nextNode->setPrev(prevNode);
                delete temp;
            }
        }
    }

    void printDLL()
    {
        Node<t> *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};

int main()
{
    dll<int> a;
    a.deleteElement(1);
    a.insertAtHead(2);
    a.insertAtHead(4);
    a.insertAtTail(50);
    a.insertAtHead(2);
    a.printDLL();

    return 0;
}