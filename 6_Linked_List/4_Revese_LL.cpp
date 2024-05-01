
#include<iostream>
#include<iomanip>
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
        cout<<setw(5)<<temp->data;
        temp= temp->next;
    }
    cout<<endl;
}


node* loopreverse(node*& head)
{
    if(head==NULL || head->next==head)
        return head;
    
    node*previous=NULL;
    node*current=head;
    while (current!=NULL)
    {
        node*forward=current->next;
        current->next=previous;
        previous=current;
        current=forward;
    }
    return previous;
    
}
node* recursionreverse(node* previous, node* current)
{
    if(current==NULL)
        return previous;
    
    node*forward=current->next;
    current->next=previous;
    return recursionreverse(current, forward);
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

    head=loopreverse(head);
    print(head);
    head=recursionreverse(NULL, head);
    print(head);

    
    return 0;
}