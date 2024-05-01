
#include<iostream>
using namespace std; 

class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void insertAtPosition(node*&head, node*&tail, int position, int data)
{
    if(position==1)
    {
        if(head==NULL)
        {
            node* newnode=new node(data);
            head=newnode;
        }
        else
        {
            node* newnode=new node(data);
            newnode->next=head;
            head=newnode;
        }
        return;
    }
    node* beforePosi=head;
    int count=1;
    while (count<position-1)
    {
        beforePosi=beforePosi->next;
        count++;
    }
    if(beforePosi->next==NULL)
    {
        if(tail==NULL)
        {
            node* newnode=new node(data);
            tail=newnode;
        }
        else
        {
            node* newnode=new node(data);
            tail->next=newnode;
            tail=newnode;
        }
        return;
    }

    node* newnode= new node(data);
    newnode->next=beforePosi->next;
    beforePosi->next=newnode;
}

void print(node*& head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

node* kReverse(node* head, int k)
{
    if(head==NULL)
    {  
        return NULL;
    }

    node*next=NULL;
    node*current=head;
    node*previous=NULL;
    int count=0;

    while (current!=NULL && count<k )
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
        count++;
    }
    if(next!=NULL)
    {
        head->next=kReverse(next,k);
    }
    return previous;
    
}

int main()
{
    node* n1=new node(10);
    node* head=n1;
    node* tail=n1;

    insertAtPosition(head,tail,1,5);
    insertAtPosition(head, tail,2,10);
    insertAtPosition(head, tail,3,15);
    insertAtPosition(head,tail,4,20);
    insertAtPosition(head, tail,5,25);
    insertAtPosition(head, tail,6,30);
    print(head);
    head=kReverse(head,2);
    print(head);


    
    return 0;
}