#include<iostream>
using namespace std;

void merge(int *arr ,int start ,int end)
{
    int mid=start+(end-start)/2;

    int len1=mid-start+1;
    int len2=end-mid;

    int *first =new int[len1];
    int *second =new int[len2];

    // copy

    // first array copy

    int mainArrayIndex=start;
    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[mainArrayIndex++];
    }

    // second array copy

    mainArrayIndex=mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i]=arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=start;

    while (index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayIndex++]=first[index1++];
        }
        else
        {
            arr[mainArrayIndex++]=second[index2++];
        }
    }
    while (index1<len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }
    while (index2<len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }

    delete []first;
    delete []second;

}

void mergesort(int *arr, int start, int end)
{
    if(start>=end)
        return;

    int mid= start+(end-start)/2;

    // left part sort
    mergesort(arr,start,mid);

    // right part sort
    mergesort(arr, mid+1, end);

    // merge
    merge(arr,start, end);

}

int main()
{
    int arr[7]={38,27,43,3,9,82,10};
    mergesort(arr,0,6);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
