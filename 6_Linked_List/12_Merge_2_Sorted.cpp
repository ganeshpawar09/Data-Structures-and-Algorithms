#include<iostream>
#include<map>
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

void solve(node*& first, node*& second)
{
    if(first==NULL)
        return;
    if(second==NULL)
        return;

    node* curr1=first;
    node* next1=first->next;
    node* curr2=second;
    node* next2=NULL;

    while (next1!=NULL && curr2!=NULL)
    {
        if(curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            next2=curr2->next;
            curr2->next=next1;
            curr1->next=curr2;
            curr1=curr1->next;
            curr2=next2;
        }
        else
        {
            curr1=next1;
            next1=next1->next;
        }
    }
    if(next1==NULL)
        curr1->next=curr2;

}

 

int main()
{
    node* n1=new node(2);
    node* head1=n1;
    node* tail=n1;

    insertAtPosition(head1, tail,2,4);
    insertAtPosition(head1, tail,3,6);
    insertAtPosition(head1,tail,4,8);
    print(head1);

    node* n2=new node(3);
    node* head2=n2;
    node* tail2=n2;

    insertAtPosition(head2, tail2,2,5);
    insertAtPosition(head2, tail2,3,7);
    print(head2);

    if(head1->data<head2->data)
    {
        solve(head1, head2);
        print(head1);
    }
    else
    {
        solve(head2, head1);
        print(head2);
    }

   
    return 0;
}