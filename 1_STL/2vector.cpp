// VECTOR

#include<iostream>
#include<vector>
using namespace std; 

int main()
{
    vector<int> vec;  

    cout<<"Size :"<<vec.capacity()<<" "<<vec.size()<<endl;

    vec.push_back(34);
    cout<<"Size :"<<vec.capacity()<<" "<<vec.size()<<endl;

    vec.push_back(4);
    cout<<"Size :"<<vec.capacity()<<" "<<vec.size()<<endl;

    vec.push_back(3);
    cout<<"Size :"<<vec.capacity()<<" "<<vec.size()<<endl;

    cout<<"Element at 2nd index :"<<vec.at(2)<<endl;

    cout<<"First :"<<vec.front()<<endl;

    cout<<"Last :"<<vec.back()<<endl;

    cout<<"Before Pop "<<endl;

    for (int i: vec)
    {
        cout<<i<<" ";
    }cout<<endl;

    vec.pop_back();

    for (int j: vec)
    {
        cout<<j<<" ";
    }cout<<endl;
    

    cout<<"Before :"<<vec.size()<<endl;

    vec.clear();

    cout<<"After :"<<vec.size()<<endl;

    return 0;
}