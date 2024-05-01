// detect loop in linked list

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

//**************only for circular linked list
// bool isCircular(Node* head){

//     if(head==NULL)
//         return false;
    
//     Node* temp=head->next;
//     while(temp!=head && temp!=NULL)
//     {
//         temp=temp->next;
//     }
//     if (temp==head)
//         return true;
//     else
//         return false;
// }



// Using map (loop and circular also)

bool detect_loop(node*head)
{
    if(head==NULL)
        return false;

    map<node*,bool>visited;

    node*temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {   
            cout<<"Startin element of loop: "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}   

// using floyd's cycle detection algo (loop and circular also)

bool detect_loop1(node* head)
{
    if(head==NULL)
        return false;
    node* slow =head;
    node* fast =head;
    while (slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        if(fast==slow)
            return true;
    }
    return false;
}
// **************************************Get starting of loop

node* get_starting_Loop(node*head)
{
    if(head==NULL)
        return NULL;

    map<node*,bool>visited;

    node*temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {   
            return temp;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return NULL;
}   
node* get_starting_Loop1(node* head)
{
    if(head==NULL)
        return NULL;

    node* slow =head;
    node* fast =head;
    while (slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        if(fast==slow)
        {
            break;
        }
    }
    slow=head;
    while (slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow;
}

int main()

{
    node *n1=new node (10);
    node *head=n1;
    node *tail=n1;

    insertAtPosition(head,tail,2,5);
    insertAtPosition(head,tail,3,15);
    insertAtPosition(head,tail,4,20);
    insertAtPosition(head,tail,5,25);
    insertAtPosition(head,tail,6,30);

    tail->next=(head->next)->next;


    if(detect_loop(head))
        cout<<"Linked list is circular"<<endl;
    else
        cout<<"Linked list is not circular"<<endl;

    if(detect_loop1(head))
        cout<<"Linked list is circular"<<endl;
    else
        cout<<"Linked list is not circular"<<endl;

    cout<<get_starting_Loop(head)->data<<endl;
    cout<<get_starting_Loop1(head)->data<<endl;
        
    return 0;
}