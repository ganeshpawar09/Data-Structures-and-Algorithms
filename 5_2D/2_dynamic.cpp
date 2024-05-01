#include<iostream>
using namespace std; 

int main()
{
    // int n=3;
    // int m=3;
    // int **arr=new int*[n];
    // for (int i = 0; i <n; i++)
    // {
    //     arr[i]=new int[m];
    // }
    // for (int i = 0; i <n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin>>arr[i][j];
    //     }cout<<endl;
    // }
    
    // for (int i = 0; i <n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }

    int n=3;
    int m=3;

    int **arr=new int*[n];
    for (int i = 0; i <n; i++)
    {
        arr[i]=new int[m];
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m+i; j++)
        {
            cin>>arr[i][j];
        }cout<<endl;
    }
    
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m+i; j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    // deletion of internal row 
    for (int i = 0; i <n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    
    cout<<"deleted"<<endl;
    
    return 0;
}