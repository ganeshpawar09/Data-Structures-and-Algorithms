#include<iostream>
#include<queue>
using namespace std; 

class Deque
{
    int size;
    int *arr;
    int front;
    int rear;
    public:
    Deque(int size)
    {
        this->size=size;
        arr= new int [size];
        front=-1;
        rear=-1;
    }
    bool isEmpty()
    {
        if(front==-1)
            return true;
        else 
            return false;
    }
    bool isFull()
    {
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))

            return true;
        else 
            return false;
    }
    bool pushfront(int data)
    {
        if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front=rear=0;
        }
        else if(front==0)
        {
            front=size-1;
        }
        else
        {
            front--;
        }
        arr[front]=data;
        return true;
    }
    bool pushback(int data)
    {
        if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front=rear=0;
        }
        else if(rear==size-1 )
        {
            rear= 0;
        }
        else 
        {
            rear++;
        }
        arr[rear]=data;
        return true;
        
    }
    int  popfront()
    {
        if(isEmpty())
        {
            return -1;
        }

        int ans=arr[front];
        arr[front]=-1;
        
         if(rear==front)
        {
            rear=front=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return ans;
    }
    int popback()
    {
        if(isEmpty())
        {
            return -1;
        }

        int ans= arr[front];
        arr[rear]=-1;

        if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            rear= size-1;
        }
        else 
        {
            rear--;
        }
        return true;
        
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }
};

int main()
{
    Deque a(3);
    a.print();
    cout<<a.pushfront(1)<<endl;
    cout<<a.pushback(2)<<endl;
    cout<<a.pushback(4)<<endl;
    a.print();

    cout<<a.popback()<<endl;
    cout<<a.popfront()<<endl;

    a.print();
    return 0;
}