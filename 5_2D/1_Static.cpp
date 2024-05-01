#include<iostream>
using namespace std; 

int main()
{
    int n =3;
    int m =3;

    int arr[3][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m+i; j++)
        {
            cin>>arr[i][j];
        }cout<<endl;
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m+i; j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
        
    }
    
    return 0;
}