// DEQUE 


#include<iostream>
#include<deque>
using namespace std; 


int main()
{
    deque<int>d;

    d.push_back(34);

    d.push_front(12);

    d.push_back(4);


    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;

    d.pop_back();

    d.pop_front();

    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;

    cout<<d.at(0)<<endl;

    cout<<d.empty()<<endl;

    d.erase(d.begin(),d.begin()+1);
    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}