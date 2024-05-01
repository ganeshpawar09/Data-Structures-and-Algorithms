#include<iostream>
#include<stack>
using namespace std; 

void solve(stack<int>& a, int x)
{
    if(a.empty())
    {
        a.push(x);
        return;
    }
    int temp=a.top();
    a.pop();
    solve(a,x);
    a.push(temp);
}

int main()
{
    stack<int>a;
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);

    solve(a,0);
    while(!a.empty())
    {
        cout<<a.top()<<endl;
        a.pop();
    }
    
    return 0;
}