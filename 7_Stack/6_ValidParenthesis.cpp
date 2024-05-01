#include<iostream>
#include<stack>
using namespace std; 
bool isValidParenthesis(string a)
{

    stack<char>s;
    for (int i = 0; i < a.length(); i++)
    {
        if(a[i]=='[' ||a[i]=='(' || a[i]=='{')
            s.push(a[i]);
       
        else if(s.empty())
        {
            if(a[i]==']' ||a[i]==')' || a[i]=='}')
                return false;
        }
        else if(!s.empty())
        {
            if(a[i]==']' && s.top()=='[' || a[i]=='}' && s.top()=='{'|| a[i]==')' && s.top()=='(')
                s.pop();
            else 
                return false;
        }     
    }
    return s.empty();
}

int main()
{
    string a="{[{({})}]}";
    cout<<isValidParenthesis(a)<<endl;

    return 0;
}