#include<iostream>
#include<map>
using namespace std; 


class node
{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
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

void removeDuplicates(node*&head)
{
    node* curr=head;
    while (curr->next!= NULL && curr!=NULL)
    {
        if((curr->data)==((curr->next)->data))
        {
            node*forward=curr->next;
            curr->next=forward->next;
            forward->next=NULL;
            delete forward;
        }
        else
        {
            curr=curr->next;
        }
    } 
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

int main()
{
    node*n1=new node(10);
    node*tail=n1;
    node*head=n1;
    insertAtPosition(head,tail,2,10);
    insertAtPosition(head,tail,3,10);
    insertAtPosition(head,tail,4,20);
    insertAtPosition(head,tail,5,20);
    insertAtPosition(head,tail,6,20);
    print(head);
    removeDuplicates(head);
    print(head);
    
    return 0;
}