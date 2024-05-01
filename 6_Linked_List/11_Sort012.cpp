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
    // Linked list is empty so we created new node and point it as head, tail;
    node* newNode= new node(data);
    tail->next=newNode;
    tail=newNode;
}
void insertAtTail(node*& tail,node* temp)
{
    tail->next=temp;
    tail=temp;
}

void print(node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<"   ";
        head=head->next;
    }cout<<endl;
}

node* sort012(node*head)
{
  
    node*head_zero=new node(-1);
    node*tail_zero=head_zero;
    node*head_one=new node(-1);
    node*tail_one=head_one;
    node*head_two=new node(-1);
    node*tail_two=head_two;

    node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==0)
        {
            insertAtTail(tail_zero,temp);
        }
        else if(temp->data==1)
        {
            insertAtTail(tail_one,temp);
        }
        else if(temp->data==2)
        {
            insertAtTail(tail_two,temp);
        }
        temp=temp->next;
    }
    if(head_one->next==NULL)
        tail_zero->next=head_two->next;
    else
    {
        tail_zero->next=head_one->next;
        tail_one->next=head_two->next;
    }
    tail_two->next=NULL;
    node*ans=head_zero->next;
    delete head_zero;
    delete head_two;
    delete head_one;
    return ans;
}



int main()
{
    node*n1=new node(0);
    node*tail=n1;
    node*head=n1;
    insertAtTail1(tail,1);
    insertAtTail1(tail,2);
    insertAtTail1(tail,0);
    insertAtTail1(tail,2);
    insertAtTail1(tail,1);
    insertAtTail1(tail,0);
    insertAtTail1(tail,0);
    print(head);
    node* temp =sort012(head);
    print(head);
    print(temp);
    
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std; 

// class Node
// {
//     public:
//     int data;
//     Node *next;

//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };

// void insertAtTail1(Node*&tail, int data)
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

// void print(Node*& head)
// { 
//     Node* temp=head;
//     while (temp!=NULL)
//     {
//         cout<<temp->next<<" ";
//         temp= temp->next;
//     }
//     cout<<endl;
// }
// void insertAtTail(Node* &tail, Node* curr ) 
// {
//     tail -> next = curr;
//     tail = curr;
// }
// void Sort012(Node *&head)
// {
//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;
//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;
//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;
    
//     Node* curr = head;
    
//     // create separate list 0s, 1s and 2s
//     while(curr != NULL) {
        
//         int value = curr -> data;
        
//         if(value == 0) {
//             insertAtTail(zeroTail, curr);
//         }
//         else if(value == 1) {
//             insertAtTail(oneTail, curr);
//         }
//         else if(value == 2) {
//             insertAtTail(twoTail, curr);
//         }       
//         curr = curr -> next;
//     }
    
//     //merge 3 sublist
    
//     // 1s list not empty
//     if(oneHead -> next != NULL) {
//         zeroTail -> next = oneHead -> next;
//     }
//     else {
//         //1s list -> empty
//         zeroTail -> next = twoHead -> next;
//     }
    
//     oneTail -> next = twoHead -> next;
//     twoTail -> next = NULL;
    
// 	//setup head 
//     head = zeroHead -> next;
    
//     //delete dummy nodes
//     delete zeroHead;
//     delete oneHead;
//     delete twoHead;

// }

// int main()
// {
//     Node*n1=new Node(1);
//     Node*tail=n1;
//     Node*head=n1;
//     insertAtTail1(tail,1);
//     insertAtTail1(tail,0);
//     insertAtTail1(tail,1);
//     insertAtTail1(tail,2);
//     insertAtTail1(tail,1);
//     insertAtTail1(tail,0);
//     insertAtTail1(tail,1);
//     print(head);
//     Sort012(head);
//     print(head);
    
//     return 0;
// }