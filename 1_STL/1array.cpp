// STL

// 1 Array

#include<iostream>
#include<array>
using namespace std; 


int main()
{
    array<int,4> a={1,2,3,4};
    int size =a.size();
    cout<<size<<endl;
    
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<"Element at 2nd index :"<<a.at(2)<<endl;

    cout<<"Empety or not :"<<a.empty()<<endl;

    cout<<"First Element :"<<a.front()<<endl;

    cout<<"Last Element :"<<a.back()<<endl;
    
    
    return 0;
}

