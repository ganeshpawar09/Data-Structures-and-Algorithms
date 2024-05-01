// set 

#include<iostream>
#include<set>
using namespace std; 

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(4);
    s.insert(4);
    s.insert(1);
    s.insert(8);
    s.insert(9);
    // for(auto i:s)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;

    // cout<<s.count(4)<<endl;
    
    // set<int>::iterator it= s.begin();

    // cout<<*it<<endl;
    // it++;
    // it++;

    // cout<<*it<<endl;

    set<int>::iterator f= s.find(5);

    cout<<*f<<endl;

    




    
    return 0;
}