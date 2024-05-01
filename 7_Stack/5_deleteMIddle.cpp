#include<iostream>
#include<stack>

using namespace std; 

void solve(stack<int>&a, int count,int size)
{
    if(count==size/2)
    {
        a.pop();
        return;
    }
    int b=a.top();
    a.pop();
    solve(a,count+1,size);
    a.push(b);
}

int main()
{
    stack<int>b;
   
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.push(5);

    solve(b,0,4);
    while (b.empty()!=true)
    {
        cout<<b.top()<<endl;
        b.pop();
    }
    
    


    return 0;
}