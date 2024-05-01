#include<iostream>
using namespace std;

long double solve(double a,int n)
{
   
    long double ans=0;
    while(a<=n)
    {   
        long double b=a*a;
        if(b<n)
            ans=a;
        a+=.00001;
    }
    return ans;
}
long double mySqrt(int x) 
{    
    long double ans=-1;
    long double s=0.0; float e=x;
    while(s<=e)
    {
        long double mid= s+(e-s)/2.0;
        long double a=mid*mid;
        if(a==x)
        {
            return mid;
        }
        else if(a<x)
        {
            s=mid+1;
            ans=mid;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}

int main()
{
    int num=8;
    long double ans=mySqrt(num);
    cout<<solve(ans,num);
    
    return 0;
}