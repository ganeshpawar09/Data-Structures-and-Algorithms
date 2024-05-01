#include<iostream>
using namespace std;
int factorial(int n) 
{
    if(n==0)  //base case
        return 1;
    
    return n*factorial(n-1);
}

int TwoRaiseToN(int n)
{
    if(n==0)
        return 1;
    
    return 2*TwoRaiseToN(n-1);
}

void counting(int n)
{
    if(n==0)
        return ;
    cout<<n ;
    counting(n-1);

}

int main()
{
    int a; 
    cin>>a;
    cout<<factorial(a)<<endl;
    cout<<TwoRaiseToN(a)<<endl;
    counting(a); 
    
    return 0;
}