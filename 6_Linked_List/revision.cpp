#include <iostream>
using namespace std;

class node
{
    int data;
    node* next;
    public:
    node()
    {
        this->data=NULL;
        this->next=NULL;
    }

    void setNext(node* n)
    {
        next=n;
    }
    void setdata(int n)
    {
        data=n;
    }
    node* getNext()
    {
        return next;
    }
    int getdata()
    {
        return data;
    }
};

class ll
{
    node*head; 
    node*tail;

    public:
    ll()
    {
        head=tail=NULL;
    }

    void insertAtHead(int data)
    {
        node* newNode=new node();
        newNode->setdata(data);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        newNode->setNext(head);
        head=newNode;
    }
    void insertAtTail(int data)
    {
        node* newNode=new node();
        newNode->setdata(data);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        tail->setNext(newNode);
        tail=newNode;
    }
    void insertAfterValue(int data,int value)
    {
        node* newNode=new node();
        newNode->setdata(data);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        node* temp=head;
        while (temp->getdata()!=value && temp->getNext()!=NULL)
        {
            temp=temp->getNext();
        }
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        
    }
    
};

int main()
{
    return 0;
}