// STACK
// last in first out 

#include<iostream>
#include<stack>

using namespace std; 

int main()
{
    stack<string>s;

    s.push("GANESH");
    s.push("AVACHIT");
    s.push("PAWAR");

    cout<<"Top element :"<<s.top()<<endl;
    cout<<s.size()<<endl;

    s.pop();

    cout<<"Top element :"<<s.top()<<endl;
    cout<<s.size()<<endl;

    




    
    return 0;
}