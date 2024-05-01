// Median of row wise sorted matrix

#include<iostream>
#include<vector>
using namespace std; 

int find_less_than_or_equal_to_mid(vector<int>&vec, int key)
{
    int s=0;
    int e=vec.size()-1;
    while (s<e)
    {
        int mid=s+(e-s)/2;
        if(vec[mid]<=key)
            s=mid+1;
        else
            e=mid;
    }
    return s;
    
}
int solve(vector<vector<int>>&vec)
{
    int s=1;
    int e=1e9;
    int n=vec.size();
    int m=vec[0].size();
    int midofvec=(n*m)/2;

    while (s<e)
    {
        int count=0;
        int mid=s+(e-s)/2;
        for (int i = 0; i < vec.size(); i++)
        {
            count+=find_less_than_or_equal_to_mid(vec[i],mid);
        }
        if(count<=midofvec) 
            s=mid+1;
        else
            e=mid;  
    }
    return s;
}


int main()
{

    // vector<vector<int>>vec={{1,3,6,},{2,6,9,},{3,6,9},{7,7,9},{9,9,9}};
    vector<vector<int>>vec={{1,3,4,5,6,7}};
    // vector<vector<int>>vec={{1,3,6,},{2,6,9,},{3,6,9},{7,7,9},{9,9,9}};
    // vector<vector<int>>vec={{1,3,6,},{2,6,9,},{3,6,9},{7,7,9},{9,9,9}};
    cout<<solve(vec);
    return 0;
}