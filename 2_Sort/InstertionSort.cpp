#include<iostream>
using namespace std; 

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
     }
     for (int i = 0; i < 10; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    
}



int main()
{
    int arr[10]={10,9,8,11,6,5,4,3,2,1};
    insertion_sort(arr,10);

    return 0;
}