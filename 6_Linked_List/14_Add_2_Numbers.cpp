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
        this->next=NULL;
    }
};

void insertAtTail(node *& tail, int data)
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
}

node* reverse(node*&head)
{
    if(head->next==NULL)
        return head;
    node* prev=NULL;
    node* curr=head;
    while (curr!=NULL)
    {
        node*forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void solve(node* &head1, node* &head2, node* &head3, node* &tail)
{
    head1=reverse(head1);
    head2=reverse(head2);
    int sum=0;
    int prevsum=0;
    int h1h2=0;
    
    while (head1!=NULL && head2!=NULL)
    {
        h1h2=(head1->data)+(head2->data)+prevsum;
        sum=h1h2%10;
        prevsum=h1h2/10;
        insertAtTail(tail,sum);
        head1=head1->next;
        head2=head2->next;
    }
    if(head1==NULL)
    {
        while (head2!=NULL)
        {
            h1h2=(head2->data)+prevsum;
            sum=h1h2%10;
            prevsum=h1h2/10;
            insertAtTail(tail,sum);
            head2=head2->next;
        }
    }
    if(head2==NULL)
    {
        while (head1!=NULL)
        {
            h1h2=(head1->data)+prevsum;
            sum=h1h2%10;
            prevsum=h1h2/10;
            insertAtTail(tail,sum);
            head1=head1->next;
        }
    }
    if(prevsum!=0)
        insertAtTail(tail,prevsum);
    
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
    node* n1=new node(9);
    node* head1=n1;
    node* tail1=n1;
    insertAtTail(tail1,4);
    insertAtTail(tail1,5);


    node* n2=new node(7);
    node* head2=n2;
    node* tail2=n2;
    insertAtTail(tail2,0);

    node* n3=new node(-1);
    node* head3=n3;
    node* tail3=n3;

    print(head1);
    print(head2);
    

    solve(head1,head2,head3,tail3);

    head3=reverse(head3->next);
    print(head3);
    

    return 0;
}