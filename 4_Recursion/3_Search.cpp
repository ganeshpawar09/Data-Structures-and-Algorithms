#include<iostream>
using namespace std; 


bool is_Sorted(int *arr,int size)
{
    if(size==1 || size==0)
        return true;
    if(arr[0]>arr[1])
        return false;
    else
        return is_Sorted(arr+1, size-1);
}

int sum(int* arr, int size )
{
    if (size==0)
        return 0;
    

    int ans=arr[0]+sum(arr+1,size-1);
    return ans;
}

int Search(int* arr, int size,int key )
{
    if (size==0)
        return 0;
    if(arr[0]==key)
        return 1;
    else
        return Search(arr+1, size-1, key);

}

int binaray_search(int *arr,int size, int target,int start=0)
{
    if(start>(size-1))
        return -1;

    int mid= start+((size-1)-start)/2;

    if (arr[mid]==target)
        return mid;
    else if(arr[mid]<target)
        return binaray_search(arr,size,target,mid+1);
    else
        return binaray_search(arr,mid-1,target,start);

}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<binaray_search(arr,10,10)<<endl;
    cout<<is_Sorted(arr,10)<<endl;
    cout<<sum(arr,10)<<endl;
    cout<<Search(arr,10,11);


    return 0;
}