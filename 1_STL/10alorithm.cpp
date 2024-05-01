// Alorithm 
// binary search

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std; 

int main()
{
    vector<int>vec;

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(9);

    cout<<"FINDING 7 :"<<binary_search(vec.begin(), vec.end(),7)<<endl;

    cout<<"Lower Bound :"<<lower_bound(vec.begin(), vec.end(),7)-vec.begin()<<endl;
    
    cout<<"Upper Bound :"<<upper_bound(vec.begin(), vec.end(),7)-vec.begin()<<endl;
    

    // min max
    int a=3;
    int b=5;
    cout<<"Max :"<<max(a,b)<<endl;
    cout<<"Min :"<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a :"<<a<<endl
    <<"b :"<<b<<endl;

    //reverse 

    string s= "abcd";
    reverse(s.begin(),s.end());
    cout<<s<<endl;

    // rotate
    for(int i:vec)
    {
        cout<<i<<" ";
    }cout<<endl;

    rotate(vec.begin(),vec.begin()+1,vec.end());
    for(int i:vec)
    {
        cout<<i<<" ";
    }cout<<endl;

    sort(vec.begin(), vec.end());
    for(int i:vec)
    {
        cout<<i<<" ";
    }cout<<endl;

    cout<<vec.at(3)<<endl;



    
    return 0;
}