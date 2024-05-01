// ***********Minimum cost to make string valid

#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str) {
    stack<char>a;
    if(str.length()%2!=0)
        return -1;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='{')
            a.push(str[i]);
        if(str[i]=='}')
        {
            if(!a.empty() && a.top()=='{')
                a.pop();
            else
                a.push(str[i]);
        }    
    }
    
    
    
    int count=0;
    int count1=0;
    while(!a.empty())
    {
        if(a.top()=='{')
        {
            count++;
            a.pop();
        }
        else if(a.top()=='}')
        {
            count1++;
            a.pop();
        }
    }
    if(count!=0 && count1==0 || count==0 && count1!=0 )
        return (count+count1)/2;
    else 
        return ((count/2)+(count1/2)+(count%2)+(count1%2));
    
}

int main()
{
    string a="{}{}{}{}}}}}{{";
    cout<<findMinimumCost(a);

    return 0;
}