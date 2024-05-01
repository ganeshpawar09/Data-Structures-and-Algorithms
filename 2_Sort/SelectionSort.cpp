#include<iostream>
using namespace std; 

void selectionsort(int *arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int index_tobe_sorted=i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j]<arr[index_tobe_sorted])
                index_tobe_sorted=j;
        }
        swap(arr[i],arr[index_tobe_sorted]);
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }cout<<endl;
}

int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    selectionsort(arr,10);

    
    return 0;
}