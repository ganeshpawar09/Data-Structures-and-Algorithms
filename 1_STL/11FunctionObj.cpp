// function object

#include<iostream>
#include<functional>
#include<algorithm>
using namespace std; 

int main()
{
    // function objects (functor) :function wrapped in a class so that
    // it available like a object
    int a=43;
    int arr[10]={a,5,2,3,4,6,1};
    sort(arr,arr+7);
    // sort(arr,arr+7,greater<int>());

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}