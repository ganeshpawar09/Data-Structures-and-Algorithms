// max no of pages 
// alloted is minimum

#include<iostream>
using namespace std; 

bool is_max(int *arr,int mid, int size, int student)
{
    int pages=0;
    int s1=1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]>mid) return false;
        if(pages+arr[i]>mid)
        {  
            pages=arr[i];
            s1+=1;
        }
        else 
            pages+=arr[i];
    }
    if(s1!=student)
        return 0;
    else 
        return 1;
    
}

int solve(int *arr, int size,int student)
{
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum=sum+arr[i];
    }
    int low=arr[0];
    int high=sum;
    int ans=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(is_max(arr,mid,  size, student))
        {
            ans=mid;
            high=mid-1;
        }
        else 
            low =mid+1;
    }
    return ans;
    
    
}

int main()
{
    int arr[4]={12,34,67,90};
    cout<<solve(arr,4,2);
    
    return 0;
}