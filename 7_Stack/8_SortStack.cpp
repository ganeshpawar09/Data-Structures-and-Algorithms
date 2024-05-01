#include<iostream>
#include<stack>
using namespace std; 

void solve(stack<int> &a, int x)
{
    if(a.empty())
    {
        a.push(x);
        return;
    }
    int temp=a.top();
    if(temp>x)
    {
        a.pop();
        solve(a,x);
        a.push(temp);
    }
    else
    {
        a.push(x);
    }    
}

void sortStack(stack<int> &a)
{
    if(a.empty())
        return;
    int temp=a.top();
    a.pop();
    sortStack(a);
    solve(a,temp);
}



int main()
{

    stack<int>a;
    a.push(10);
    a.push(9);
    a.push(8);
    a.push(7);
    a.push(6);
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);
    cout<<a.top()<<endl;
    sortStack(a);
    cout<<a.top()<<endl;



    
    
    
    return 0;
}