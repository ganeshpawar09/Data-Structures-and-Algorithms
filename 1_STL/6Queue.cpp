// QUEUE

// first in first out 

#include<iostream>
#include<queue>
using namespace std; 

int main()
{
    queue<string>q;

    q.push("GANESH");
    q.push("AVACHIT");
    q.push("PAWAR");
    
    cout<<"Top element :"<<q.front()<<endl;
    cout<<"last element :"<<q.back()<<endl;

    cout<<q.size()<<endl;

    q.pop();

    cout<<"Top element :"<<q.front()<<endl;
    cout<<"last element :"<<q.back()<<endl;

    cout<<q.size()<<endl;

    return 0;
}