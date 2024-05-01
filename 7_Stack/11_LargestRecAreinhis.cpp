// largest rectangular area in histogram

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> next(vector<int>arr,int n)
{
    stack<int>s;
    vector<int>ans(n);
    s.push(-1);
    for (int i = n-1; i >= 0 ; i--)
    {
        int curr=arr[i];
        while (s.top()!=-1 && arr[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);  
    }
    return ans;
}

vector<int> prev(vector<int>arr,int n)
{
    stack<int>s;
    vector<int>ans(n);
    s.push(-1);
    for (int i = 0; i < n ; i++)
    {
        int curr=arr[i];
        while (s.top()!=-1 && arr[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);  
    }
    return ans;         
}



int main()
{
    vector<int>arr={1,2,2};
    int n= arr.size();
    vector<int>nextsmall;
    vector<int>prevsmall;
    
    nextsmall=next(arr, n);
    prevsmall=prev(arr, n);
    
    int max_area=INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        int len=arr[i];
        if(nextsmall[i]==-1)
            nextsmall[i]=n;
        
        int bre=nextsmall[i]-prevsmall[i]-1;

        int newarea=len*bre;

        max_area=max(max_area,newarea);

    }
    cout<<max_area<<endl;
    return 0;
}
