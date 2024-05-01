#include <iostream>
using namespace std;

template <class t>
class ll;

template <class t>
class Node
{
    Node *next;
    t data;

public:
    friend class ll<t>
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
class ll
{
    Node<t> *head;
    Node<t> *tail;

public:
    ll()
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
            while (temp != NULL && temp->getData() == afterIt)
            {
                temp = temp->getNext();
            }
            Node<t> *newNode = new Node<t>();
            newNode->setData(x);

            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
    }

    void deleteElement(t x)
    {
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
        }
        else if (head->getData() == x)
        {
            Node<t> *temp = head;
            head = head->getNext();
            delete temp;
        }
        else
        {
            Node<t> *temp = head;
            while (temp->getNext()->getNext() != NULL && temp->getNext()->getData() == x)
            {
                temp = temp->getNext();
            }
            if (temp->getNext()->getNext() == NULL)
            {
                tail = temp;
            }
            Node<t> *tobeDeleted = temp->getNext();
            temp->setNext(tobeDeleted->getNext());
            delete tobeDeleted;
        }
    }

    void printLL()
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
    ll<int> a;

    a.insertAtTail(1);
    a.insertAtTail(2);
    a.insertAtTail(3);
    a.insertAtTail(4);
    a.printLL();
    a.insertAtHead(5);
    a.printLL();
    a.insertAfterIt(6, 2);
    a.printLL();
    a.deleteElement(6);
    a.printLL();
    a.deleteElement(7);
    a.printLL();

    return 0;
}
