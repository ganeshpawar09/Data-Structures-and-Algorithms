#include<iostream>
#include<stack>
using namespace std; 

int main()
{
    stack<char>s;
    string a = "ganesh";
    string b = "";
    for (int i = 0; i < a.length(); i++)
    {
        s.push(a[i]);
    }

    while (s.empty()==false)
    {
        char c=s.top();
        b.push_back(c);
        s.pop();
    }
    cout<<b<<endl;
    

    
    return 0;
}