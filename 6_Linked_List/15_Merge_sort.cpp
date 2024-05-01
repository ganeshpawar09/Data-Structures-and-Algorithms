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
node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

node* merge(node* left, node* right) 
{
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}

node* mergeSort(node *head) 
{
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}
void print(node*head)
{ 
    
    while (head!=NULL)
    {
        cout<<head<<" ";
        head= head->next;
    }
    cout<<endl;
}


int main()
{
    node* n1=new node(9);
    node* head=n1;
    node* tail=n1;
    insertAtTail(tail,8);
    insertAtTail(tail,7);
    insertAtTail(tail,6);
    insertAtTail(tail,5);
    insertAtTail(tail,4);
    insertAtTail(tail,3);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    print(head);
    node*ans =mergeSort(head);
    print(head);
    print(ans);





    

    return 0;
}