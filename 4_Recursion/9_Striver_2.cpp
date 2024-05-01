#include<iostream>
using namespace std;

void reverse(int *arr, int start, int end)
{
    if(start>=end)
        return;
    swap(arr[start],arr[end]);
    reverse(arr, start+1, end-1);
}

int main() 
{
    int arr[9]={1,2,3,4,5,6,7,8,9};
    reverse(arr,0,9);

    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}