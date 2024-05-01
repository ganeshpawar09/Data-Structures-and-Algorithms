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
    ~node(){}
};

void insertAtTail1(node*& tail,int data)
{
    node* newNode= new node(data);
    tail->next=newNode;
    tail=newNode;
}

node* getmiddle(node* &head)
{
    node* slow= head;
    node* fast= head->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* reverse(node* &head)
{
    node*prev=NULL;
    node*curr=head;

    while (curr!=NULL)
    {
        node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

bool checkPalindrome(node* &head)
{
    if(head==NULL)
        return 1;
    if(head->next==NULL)
        return 1;
    node*mid=getmiddle(head);
    mid->next=reverse(mid->next);
    node* curr1=head;
    node* curr2=mid->next;
    while (curr2!=NULL)
    {
        if(curr1->data!=curr2->data)
            return false;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return true;
    
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
    node*n1=new node(3);
    node*tail=n1;
    node*head=n1;
    insertAtTail1(tail,0);
    insertAtTail1(tail,4);
    insertAtTail1(tail,5);
    insertAtTail1(tail,5);
    insertAtTail1(tail,4);
    insertAtTail1(tail,3);
    insertAtTail1(tail,2);
    cout<<checkPalindrome(head)<<endl;    
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std; 

// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };

// void insertAtTail(Node *& tail, int data)
// {
//     if(tail==NULL)
//     {
//         Node* newnode=new Node(data);
//         tail=newnode;
//     }
//     else
//     {
//         Node* newnode=new Node(data);
//         tail->next=newnode;
//         tail=newnode;
//     }
// }


// Node* getMid(Node* head)
// {
//     Node*slow=head;
//     Node*fast=head->next;

//     while (fast!=NULL && fast->next!=NULL)
//     {
//         slow=slow->next;
//         fast=fast->next;
//         if(fast->next!=NULL)
//             fast=fast->next;
//     }
//     return slow;
// }

// Node* reverse(Node*&head)
// {
//     if(head->next==NULL)
//         return head;
//     Node* prev=NULL;
//     Node* curr=head;
//     while (curr!=NULL)
//     {
//         Node*forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//     }
//     return prev;
// }

// bool check_palindrome(Node*head)
// {
//     if(head==NULL)
//         return false;
//     if(head->next==NULL)
//         return true;
//     if(head->data==(head->next)->data && (head->next)->next==NULL)
//         return true;
//     if(head->data!=(head->next)->data && (head->next)->next==NULL)
//         return false;

//     Node*mid=getMid(head);
//     mid->next=reverse(mid->next);

//     Node* s=head;
//     Node* m=mid->next;

//     while (m!=NULL)
//     {
//         if(s->data!=m->data)
//         {
//             mid=getMid(head);
//             mid->next=reverse(mid->next);
//             return false;
//         }
//         m=m->next;
//         s=s->next;
//     } 
//     mid=getMid(head);
//     mid->next=reverse(mid->next);

//     return true;

// }
// int main()
// {
//     Node* n1=new Node(5);
//     Node* head=n1;
//     Node* tail=n1;

//     insertAtTail(tail,4);
//     insertAtTail(tail,4);
//     // insertAtTail(tail,0);
//     // insertAtTail(tail,1);
//     // insertAtTail(tail,2);
//     // insertAtTail(tail,3);
//     cout<<check_palindrome(head)<<endl;

//     return 0;
// }