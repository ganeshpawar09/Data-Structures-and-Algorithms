#include<iostream>
using namespace std; 

void bubble_sort(int *arr, int size)
{
    if(size==1 ||size==0)
        return;
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    bubble_sort(arr, size-1);
}

void selection_sort(int *arr,int size)
{
    if(size==0 || size==1)
        return;
    int minindex=0;
    for (int i = 0; i < size; i++)
    {
        if(arr[minindex]>arr[i])
            minindex=i;
    }
    swap(arr[0],arr[minindex]);
    selection_sort(arr+1, size-1);
}

void insertion_sort(int *arr, int size)
{
    if(size==1 || size==0)
        return;
        

    int temp=arr[size-1];
    int i = size-2;
    for (; i >=0; i--)
    {
        if(temp>arr[i])
            arr[i+1]=arr[i];
    }
    arr[i+1]=temp;
    insertion_sort(arr,size-1);
}

int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    bubble_sort(arr,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<endl<<endl;
    int arr1[10]={10,9,8,7,6,5,4,3,2,1};
    selection_sort(arr1,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr1[i]<<" ";
    }cout<<endl;
    
    cout<<endl<<endl;
    int arr2[10]={10,9,8,7,6,5,4,3,2,1};
    insertion_sort(arr2,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr2[i]<<" ";
    }cout<<endl;
    
   
    
    
    return 0;
}