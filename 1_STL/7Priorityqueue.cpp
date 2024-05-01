// Priorityqueue

#include<iostream>
#include<queue>

using namespace std; 

int main()
{
    // when we try to remove any element it will be maximum
    // max heap
    priority_queue<int>m;

    // min heap
    priority_queue<int, vector<int>,greater<int>>n;

    m.push(1);
    m.push(2);
    m.push(3);
    m.push(4);
    m.push(5);
    
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.top()<<endl;
    
    
    n.push(1);
    n.push(2);
    n.push(3);
    n.push(4);
    n.push(5);

    cout<<n.top()<<endl;

    
    return 0;
}