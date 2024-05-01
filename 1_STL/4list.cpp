// List

#include<iostream>
#include<list>
using namespace std; 

int main()
{
    list<int> li;

    li.push_back(23);
    li.push_back(100);
    li.push_front(43);

    for(int i: li)
    {
        cout<<i<<" ";
    }cout<<endl;

    li.erase(li.begin());

    for(int i: li)
    {
        cout<<i<<" ";
    }cout<<endl;


    list<int>n(li);

    for(int i: n)
    {
        cout<<i<<" ";
    }

    
    return 0;
}