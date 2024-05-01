#include<iostream>
#include<stack>
#include<vector>
using namespace std; 

int main()
{
    stack<int>s;
    vector<int> arr ={2, 1, 4, 3};
    int n=arr.size();
    s.push(-1);
    vector<int> ans(n);
    for (int i = n-1; i >=0; i--)
    {
        int curr=arr[i];
        while(s.top()>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    for(auto i: ans)
    {
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// void findNum(stack<int>&s, vector<int>& arr1, int x)
// {
//     if(s.empty())
//     {
//         arr1.push_back(-1);
//         return;
//     }
//     int temp=s.top();
//     if(temp<x)
//     {
//         arr1.push_back(temp);
//         return;
//     }
//     s.pop();
//     findNum(s,arr1,x);
//     s.push(temp);

// }

// void solve(stack<int>&s, vector<int>& arr1)
// {
//     if(s.empty())
//         return;
    
//     int temp=s.top();
//     s.pop();
//     solve(s,arr1);
//     findNum(s,arr1,temp);
//     s.push(temp);

// }

// int main()
// {
//     stack<int>s;
//     vector<int> arr ={2, 1, 4, 3};
//     vector<int> arr1;
//     for (int i = 3; i >=0; i--)
//     {
//         s.push(arr[i]);
//     }
//     solve(s , arr1);

//     reverse(arr1.begin(),arr1.end());
//     for(auto i: arr1)
//     {
//         cout<<i<<" ";
//     }
//     return 0;
// }