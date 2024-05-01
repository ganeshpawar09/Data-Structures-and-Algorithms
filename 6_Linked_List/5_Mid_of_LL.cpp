
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


void mid(node*head)
{
    if(head==NULL)
    {
        cout<<0<<endl;
        return;
    }
    if(head->next==NULL)
    {
        cout<< head->data<<endl;
        return;
    } 

    node* slow=head;
    node* fast=head->next;
    while ((fast)!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next);
        if (fast!=NULL)
            fast=fast->next;
    }
    cout<<slow->data<<endl;
    
}

int getlen(node*&head)
{
    if(head==NULL)
        return 0;
    node*temp=head;
    int count=1;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void mid1(node*&head)
{
    int len=getlen(head);
    if(len==1 || len==2 ) 
    {  
        cout<<head->data<<endl;
        return;
    }

    node*temp=head;
    int count=1;
    while (count<(len+1)/2)
    {
        temp=temp->next;
        count++;
    }
    cout<<temp->data<<endl;;
    
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
    // insertAtPosition(head, tail,6,30);
    print(head);

    mid(head);
    // mid1(head);

    
    

    
    return 0;
}